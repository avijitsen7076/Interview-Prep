class Solution {
public:
    vector<int> productExceptSelf(vector<int>& n) {
        vector<int> res,prepro(n.size()+1,1),postpro(n.size()+1,1);
        prepro[0]=n[0],postpro[n.size()-1]=n[n.size()-1];
        for(int i=1;i<n.size();i++){
            prepro[i]*=(n[i]*prepro[i-1]);
            postpro[n.size()-i-1]*=(postpro[n.size()-i]*n[n.size()-i-1]);
        }
        res.push_back(postpro[1]);
        for(int i=1;i<n.size()-1;i++)
            res.push_back(prepro[i-1]*postpro[i+1]);
        res.push_back(prepro[n.size()-2]);
        return res;
    }
};