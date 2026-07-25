/*
//recursion+memoization
class Solution {
public:
    vector<vector<int>>dp;
    int solve(const string& w1,const string& w2,int i,int j){
        if(j==w2.size()) return w1.size()-i;
        else if(i==w1.size()) return w2.size()-j;

        if(w1[i]==w2[j]){
            return solve(w1,w2,i+1,j+1);
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int insert=1+solve(w1,w2,i,j+1);
        int replace=1+solve(w1,w2,i+1,j+1);
        int del=1+solve(w1,w2,i+1,j);

        return dp[i][j] = min(replace,min(insert,del));

    }
    int minDistance(string w1, string w2) {
        int m=w1.size();
        int n=w2.size();
        dp.assign(m,vector<int>(n,-1));
        if(m==0||n==0) return m+n;
        return solve(w1,w2,0,0);
    }
};
*/
//bottom-up
class Solution {
public:
    int minDistance(string w1, string w2) {
        int m=w1.size();
        int n=w2.size();
        if(m==0||n==0) return m+n;
        vector<vector<int>>dp;
        dp.assign(m+1,vector<int>(n+1,0));

        for(int i=0;i<=m;i++)dp[i][0]=i;
        for(int j=0;j<=n;j++)dp[0][j]=j;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(w1[i-1]==w2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    int insert=dp[i][j-1];
                    int replace=dp[i-1][j-1];
                    int del=dp[i-1][j];
                    dp[i][j]= 1+min({insert,replace,del});
                }
            }
        }
        
        return dp[m][n];
    }
};