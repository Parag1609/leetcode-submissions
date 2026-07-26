class Solution {
public:
    vector<vector<int>>dp;
    int solve(string& s,int i,int j){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==j)return dp[i][j]=1;
        
        if(s[i]==s[j]){
            return dp[i][j]= 2+solve(s,i+1,j-1);
        }
        int takei=solve(s,i,j-1);
        int takej=solve(s,i+1,j);
        return dp[i][j]= max(takei,takej);
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        if(n<=1)return n;
        int len=1;
        dp.assign(n,vector<int>(n,0));

        for(int l=1;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(i==j)dp[i][j]=1;
                else if(i+1==j &&s[i]==s[j])dp[i][j]=2;
                else if(s[i]==s[j]){
                    dp[i][j]=2+dp[i+1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
                if(dp[i][j]>len)len=dp[i][j];
            }
        }
        return len;
    }
};