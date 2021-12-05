#program once

class DisjointSet
{
public:
    DisjointSet(int size)
    {
        parent.resize(size, -1);
        rank.resize(size, 0);
    }
    
    int find_root(int x)
    {
        int x_root = x;
        while (parent[x_root] != -1)
        {
            x_root = parent[x_root];
        }
        return x_root;
    }

    bool union_xy(int x, int y)
    {
        int x_root = find_root(x);
        int y_root = find_root(y);
        if (x_root == y_root)
        {
            return false;
        }
        if (rank[x_root] > rank[y_root])
        {
            parent[y_root] = x_root;
        }
        else if (rank[x_root] < rank[y_root])
        {
            parent[x_root] = y_root;
        }
        else
        {
            parent[x_root] = y_root;
            rank[y]++;
        }
        return true;
    }

    bool connected(int x, int y) {
        x = find_root(x);
        y = find_root(y);
        return x == y;
    }

    bool disconnected(int x) {
        parent[x] = -1;
        return true;
    }

    unordered_map<int, vector<int>> getClusters() {
        unordered_map<int,vector<int>>rec;
        for (int i = 0; i < parent.size(); ++i) {
            int root = find_root(i);
            rec[root].push_back(i);
        }
        return rec;
    }

    vector<int> parent;
    vector<int> rank;
};
