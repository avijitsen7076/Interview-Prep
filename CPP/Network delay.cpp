class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto i : times){
            graph[i[0]].push_back({i[1],i[2]});
        }
        vector<int> dis(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dis[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            for(auto child : graph[temp.second]){
                int curr = child.first;
                int wt = child.second;
                if(dis[curr] > temp.first + wt){
                    dis[curr] = temp.first + wt;
                    pq.push({dis[curr],curr});
                }
            }
        }
        int res = INT_MIN;
        for(int i = 1 ; i <= n ; i++){
            res = max(res,dis[i]);
        }
        return res == INT_MAX ? -1 : res;
    }
};
