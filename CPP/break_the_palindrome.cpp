class Solution {
public:
    string breakPalindrome(string palim) {
        int n=palim.size();
        if(n==1)return "";
        for(int i=0;i<n/2;i++){
            if(palim[i]!='a'){
                palim[i]='a';
                return palim;
            }
        }
        palim[n-1]++;
        return palim;
    }
};
