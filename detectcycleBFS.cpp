#include <vector>
#include <queue>
using namespace std;

bool bfs(int src, int vis[], vector<int> adj[]) {
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                q.push({neighbor, node});  // Use current node as the parent
                vis[neighbor] = 1;
            } else if (neighbor != parent) {
                return true;  // Cycle detected
            }
        }
    }

    return false;  // No cycle detected
}

// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0};

    for (int i = 0; i < V; ++i) {
        if (!vis[i]) {
            if (bfs(i, vis, adj)) return true;
        }
    }

    return false;  // No cycle found in any component
}
