
    #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();    // Number of rows
        int m = grid[0].size(); // Number of columns
        int vis[n][m];          // Visited array to keep track of rotten oranges

        // Direction arrays for moving up, right, down, and left
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        // Queue to perform BFS, storing pairs of coordinates and time
        queue<pair<pair<int, int>, int>> q;

        // Initialize the visited array and find all initially rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0}); // Push rotten orange coordinates and time 0
                    vis[i][j] = 2;       // Mark as visited and rotten
                } else {
                    vis[i][j] = 0;       // Mark as not visited
                }
            }
        }

        // Initialize the maximum time to 0
        int tm = 0;

        // Perform BFS to rot adjacent fresh oranges
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            // Explore all 4 possible directions
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                // Check if the new position is within bounds and if the orange is fresh
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                    vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1}); // Push new rotten orange coordinates and time
                    vis[nrow][ncol] = 2;           // Mark as visited and rotten
                    tm = max(t + 1, tm);           // Update the maximum time
                }
            }
        }

        // Check if there are any fresh oranges left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] != 2 && grid[i][j] == 1)
                    return -1; // Return -1 if there's a fresh orange left
            }
        }

        return tm; // Return the minimum time required to rot all oranges
    }
};