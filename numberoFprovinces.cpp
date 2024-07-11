    #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    void dfs(int i, vector<int> als[], vector<int>& vis) {
        vis[i] = 1;
        for (auto it : als[i]) {
            if (vis[it] == 0)
                dfs(it, als, vis);
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<int> als[v]; // Initialize als as a vector of vectors
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (adj[i][j] == 1 && i != j) {
                    als[i].push_back(j);
                    als[j].push_back(i);
                }
            }
        }

        vector<int> vis(v, 0);
        int cnt = 0;
        for (int i = 0; i < v; i++) {
            if (vis[i] == 0) {
                cnt++;
                dfs(i, als, vis);
            }
        }
        return cnt;
    }
};