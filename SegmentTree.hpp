#program once

class SegmentTree {
public:
    SegmentTree(vector<int>& nums) {
        this->nums = nums;
        trees.resize(nums.size() * 4);
        build_tree(0, nums.size()-1, 0);
    }

    void build_tree(int start, int end, int node) {
        if (start == end) {
            trees[node] = nums[start];
            return;
        }
        int mid = (start + end) / 2;
        int left_node = node * 2 + 1;
        int right_node = node * 2 + 2;
        build_tree(start, mid, left_node);
        build_tree(mid + 1, end, right_node);
        trees[node] = trees[left_node] + trees[right_node];
    }

    void update_tree(int start, int end, int node, int index, int val) {
        if (start == end) {
            trees[node] = val;
            nums[index] = val;
            return;
        }
        int mid = (start + end) / 2;
        int left_node = node * 2 + 1;
        int right_node = node * 2 + 2;
        if (index >= start && index <= mid) {
            update_tree(start, mid, left_node, index, val);
        }
        else {
            update_tree(mid + 1, end, right_node, index, val);
        }
        trees[node] = trees[left_node] + trees[right_node];
    }

    int sum_tree(int start, int end, int node, int left, int right) {
        if (end < left || start > right) {
            return 0;
        }
        if (left <= start && right >= end) {
            return trees[node];
        }
        if (start == end) {
            return trees[node];
        }
        int mid = (start + end) / 2;
        int left_node = node * 2 + 1;
        int right_node = node * 2 + 2;
        int sum_left = sum_tree(start, mid, left_node, left, right);
        int sum_right = sum_tree(mid + 1, end, right_node, left, right);
        return sum_left + sum_right;
    }

    void update(int index, int val) {
        update_tree(0, nums.size() - 1, 0, index, val);
    }

    int sumRange(int left, int right) {
        return sum_tree(0, nums.size() - 1, 0, left, right);
    }
    vector<int> nums;
    vector<int> trees;
};
