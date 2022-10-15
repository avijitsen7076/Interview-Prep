//BFS of graph
//https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

//For connected graph

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> res;
        
        bool vis[V];
        for(int i=0;i<V;i++)
            vis[i]=false;
            
        queue<int>q;
        vis[0]=true;    //assigning 0 as the source vertex
        q.push(0);
        
        while(!q.empty()){
            int n=q.front();
            q.pop();
            res.push_back(n);
            
            for(auto x:adj[n])
                if(vis[x]!=true){
                    vis[x]=true;
                    q.push(x);
                }
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
} 