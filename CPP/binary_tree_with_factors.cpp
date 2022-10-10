class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int,long long int> count;
        sort(arr.begin(),arr.end());
        count[arr[0]]=1;
        long long int c,res=0;
        for(int i=1;i<arr.size();i++){
            c=1;
            for(auto x:count){
                if(arr[i]%x.first==0 && count.find(arr[i]/x.first)!=count.end())
                    c+=count[x.first]*count[arr[i]/x.first];
            }
            count[arr[i]]=c;
        }
        for(auto x:count)
            res=(res+x.second)%1000000007;
        return res;
    }
};