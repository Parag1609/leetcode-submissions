class Solution {
public:
    vector<vector<int>>dp;
    int solve(string& s,int i,int j){
        if(i>=j)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==s[j]){
            return dp[i][j]=solve(s,i+1,j-1);
        }
        int insertBeforeI=1+solve(s,i,j-1);
        int insertAfterJ=1+solve(s,i+1,j);
        return dp[i][j]=min(insertBeforeI,insertAfterJ);
    }
    int minInsertions(string s) {
        int n=s.size();
        if(n<=1)return 0;
        dp.assign(n,vector<int>(n,-1));
        return solve(s,0,n-1);
    }
};