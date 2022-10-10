class Solution
{
private:
 bool dfs(int i,string& s, unordered_map<string,int>& hp, vector<int>& dp)
    {
        if(i>=s.size())return true;
        if(dp[i]!=-1)return dp[i];
        string add;
        bool is_found=false;
        for(int j=i;j<s.size();j++)
        {
            add+=s[j];
            if(hp[add])
            {
                is_found|=dfs(j+1,s,hp,dp);
            }
        }
        return dp[i]=is_found;
    }
public:
    int wordBreak(string s, vector<string> &d) {
        unordered_map<string,int>hp;
        for(auto x: d)hp[x]++;
        vector<int>dp(s.size(),-1);
        return dfs(0,s,hp,dp);
    }
};
