         vector<vector<int>> dis(26, vector<int>(26, INT_MAX/2));
        for(int k = 0; k<26;++k){
            for(int i=0;i<26;++i){
                for(int j=0;j<26;++j){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
