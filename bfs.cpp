 #include<bits/stdc++.h>
 using namespace std;
 
 vector<int> bfsOfGraph(int V, vector<int> adj[])
{ int vis[V]= {0};
        vis[0]=1;
        queue<int> q;
        int st=0;
        q.push(st);
        vector<int> bfs;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it : adj[node]){
                if(vis[it]!=1){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }}