class Solution {
public:
    
    string longestPalindrome(string s) {
        int n=s.size();
        if (n <= 1) return s;
        int maxlen=1;
        int startidx=0;
        vector<vector<int>>dp(n,vector<int>(n,false));
        for(int l=1;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(i==j)dp[i][j]=true;
                else if(i+1==j && s[i]==s[j])dp[i][j]=true;
                else if(s[i]==s[j] && dp[i+1][j-1])dp[i][j]=true;

                if(dp[i][j] && l>maxlen){
                    maxlen=l;
                    startidx=i;
                }
            }
        }
        return s.substr(startidx,maxlen);
    }
};