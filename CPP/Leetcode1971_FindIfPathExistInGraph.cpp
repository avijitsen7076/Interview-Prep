// Problem Link: https://leetcode.com/problems/find-if-path-exists-in-graph

class Solution {
private:
    bool path(vector<int> adj_list[], vector<int> &vis, int node, int destination)
    {
        vis[node] = 1;
        for(auto it : adj_list[node])
        {
            if(it == destination)
            {
                return true;
            }
            else if(!vis[it])
            {
                if(path(adj_list, vis, it, destination))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool findPath(vector<int> adj_list[], vector<int> &vis, int source, int destination)
    {
        if(path(adj_list, vis, source, destination))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(edges.size() == 0)
        {
            return true;
        }
        vector<int> adj_list[n];
        vector<int> vis(n, 0);
        for(auto it : edges)
        {
            adj_list[it[0]].push_back(it[1]);
            adj_list[it[1]].push_back(it[0]);
        }
        if(findPath(adj_list, vis, source, destination))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
