class Solution {
public:
    int threeSumClosest(vector<int>& a, int t) {
        sort(a.begin(),a.end());
      int r=a.size()-1,res=-1,mx=INT_MAX,s,l;
        for(int i=0;i<=r;i++){
            if(i && a[i]==a[i-1])
                continue;
            l=i+1,r=a.size()-1;
            while(l<r){
                s=a[i]+a[l]+a[r];
                if(s==t)return t;
                if(s<t)l++;
                else
                    r--;
                if(abs(s-t)<mx){
                    mx=abs(s-t);
                    res=s;
                }
            }
        }
        return res;
    }
};