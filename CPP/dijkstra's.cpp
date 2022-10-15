#include<bits/stdc++.h>
using namespace std;

// Dijkstra's algorithm using priority queue

int main(){

    int n,m; cin>>n>>m;   // n = number of nodes, m = number of edges
    
    vector<pair<int,int>> graph[n+1];     // graph is a vector of pairs
    
    int u,v,w;          // u = start node, v = end node, w = weight of edge
    
    for(int i=0;i<m;i++){

        cin>>u>>v>>w;                                       // input of edges
        
        graph[u].push_back(make_pair(v,w));                 // push the edge in the graph
        
        graph[v].push_back(make_pair(u,w));                 // if the graph is undirected

    }

    int src; cin>>src;    // src = source node

    priority_queue< pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>> > pq;                  //min-heap -> pair(dist,node)
    
    vector<int> eachDist(n+1,INT_MAX);                              // eachDist[i] = distance of node i from source node
    
    eachDist[src] = 0;                                  // distance of source node from itself is 0
    
    pq.push(make_pair(0,src));                      // push source node in min-heap

    while(!pq.empty()){

        int dist = pq.top().first;                 // distance of node from source node
        
        int node = pq.top().second;                // node
        
        pq.pop();                                  // pop the node from min-heap

        for(auto it: graph[node]){

            int next = it.first;                    // next node
            
            int wt = it.second;                     // weight of edge between node and next node

            if(eachDist[next] > dist+wt){
                
                eachDist[next] = dist+wt;                   // update distance of next node from source node
                
                pq.push(make_pair(eachDist[next],next));    // push next node in min-heap
            
            }

        }

    }

    for(int i=1;i<=n;i++) cout<<eachDist[i]<<" ";      // print distance of each node from source node
    
    return 0;

}