#pragma once
class Floyd {
public:
    Floyd(int n) {
        this->n = n;
        dists.resize(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; ++i) {
            dists[i][i] = 0;
        }
    }

    void solve() {
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
                }
            }
        }
    }
public:
    int n;
    vector<vector<int>> dists;
};
