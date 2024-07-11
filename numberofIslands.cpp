     #include<bits/stdc++.h>
 using namespace std;
    void bfs(int r,int c,vector<vector<int>> &vis,vector<vector<char>> &grid ){
        vis[r][c]=1;
        queue<pair<int,int>> q;
        q.push({r,c});
        int m=grid.size();
        int n= grid[0].size();    
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            //traverse neighbours ans mark vis
            for(int delr =-1 ;delr<=1;delr++){
                for(int delc =-1 ;delc<=1;delc++){
                    int newr=row+delr;
                    int newc=col+delc;
                    if(newr >=0 && newr <m && newc>=0 && newc <n
                    && !vis[newr][newc]&& grid[newr][newc]=='1'){
                        vis[newr][newc]=1;
                        q.push({newr,newc});
                    }
                }
            }
        }
    }
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        int cnt=0;
        for(int row= 0;row<m;row++){
            for(int col=0;col<n;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
        // Code here
    }