     #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    // Depth-first search helper function to fill connected components
    void dfs(int i, int j, vector<vector<int>>& a, vector<vector<int>>& ans,
             int delrow[], int delcol[], int newc, int inic) {
        // Fill the current cell with the new color
        ans[i][j] = newc;
        int n = a.size(); // Number of rows
        int m = a[0].size(); // Number of columns

        // Explore all 4 possible directions
        for(int k = 0; k < 4; k++){
            int nr = i + delrow[k]; // Calculate new row index
            int nc = j + delcol[k]; // Calculate new column index

            // Check if the new position is within bounds, matches the initial color,
            // and has not been colored yet
            if(nr >= 0 && nc >= 0 && nr < n && nc < m && a[nr][nc] == inic && ans[nr][nc] != newc){
                dfs(nr, nc, a, ans, delrow, delcol, newc, inic); // Recursively call dfs for the new position
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& a, int sr, int sc, int color) {
        int inic = a[sr][sc]; // Initial color at the starting cell
        vector<vector<int>> ans = a; // Copy of the original grid to store the result

        // Arrays to simplify moving in 4 possible directions (up, right, down, left)
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // Start the flood fill from the starting cell
        dfs(sr, sc, a, ans, delrow, delcol, color, inic);

        return ans; // Return the modified grid
    }
};
