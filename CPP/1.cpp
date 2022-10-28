class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& n) {
        sort(n.begin(),n.end());
        vector<vector<int>> v;
        if(n.size()<3)return v;
        int i=0,j=n.size()-2;
        while(i<j){
            if(i==0||n[i]!=n[i-1])
            {
                int low=i+1,high=n.size()-1,sum=0-n[i];
                while(low<high)
                {
                    if((n[low]+n[high])==sum)
                    {
                        v.push_back({n[i],n[low],n[high]});
                        while(low<high&&n[low]==n[low+1])low++;
                        while(low<high&&n[high]==n[high-1])high--;
                        low++;
                        high--;
                    }
                    else if((n[low]+n[high])>sum)
                        high--;
                    else
                        low++;
                }
            }
            i++;
        }
        return v;
    }
};
