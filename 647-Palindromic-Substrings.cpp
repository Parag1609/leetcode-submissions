class Solution {
public:
    int countSubstrings(string s) {
        int n =s.length();

        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int count=0;
        for(int L=1;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(i==j) dp[i][j]=true;
                else if(i==j-1) dp[i][j]=(s[i]==s[j]);
                else dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                if(dp[i][j]) count++;
            }
        }
        return count;
    }
};