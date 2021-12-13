#pragma once

class Dijkstra {
public:
    Dijkstra(int n) {
        this->n = n;
        dists.resize(n, vector<int>(n, INT_MAX/2));
        for (int i = 0; i < n; ++i) {
            dists[i][i] = 0;
        }
    }

    void addEdge(int x, int y, int dist) {
        // 无向图 
        dists[x][y] = dists[y][x] = dist;
    }

    // 从0到n-1节点的最小距离
    void solve() {
        vector<bool> used(n);
        for (int i = 0; i < n; ++i) {
            int u = -1;
            for (int j = 0; j < n; ++j) {
                if (!used[j] && (u == -1 || dists[0][j] < dists[0][u])) {
                    u = j;
                }
            }
            used[u] = true;
            for (int j = 0; j < n; ++j) {
                dists[0][j] = min(dists[0][j], dists[0][u] + dists[u][j]);
            }
        }
    }
    int n;
    vector<vector<int>> dists;
};
