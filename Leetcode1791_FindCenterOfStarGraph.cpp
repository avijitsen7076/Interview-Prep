// Problem Link: https://leetcode.com/problems/find-center-of-star-graph

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = 1;
        for(auto it : edges)
        {
            if(it[0] > n)
            {
                n = it[0];
            }
            if(it[1] > n)
            {
                n = it[1];
            }
        }
        vector<int> adj_list[n+1];
        for(auto it : edges)
        {
            adj_list[it[0]].push_back(it[1]);
            adj_list[it[1]].push_back(it[0]);
        }
        int pre_center;
        for(int i=1; i<n+1; i++)
        {
            if(adj_list[i].size() == n-1)
            {
                pre_center = i;
            }
        }
        return pre_center;
    }
};