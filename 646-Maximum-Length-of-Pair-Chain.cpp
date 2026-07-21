/*
//bottom-up
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<int>dp(pairs.size(),1);
        sort(pairs.begin(),pairs.end());
        int lchain=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
           lchain=max(lchain,dp[i]);
        }
        return lchain;
    }
};*/
//memoization
class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<vector<int>>& pairs,int idx,int previdx){
        if(idx>=pairs.size())return 0;

        if(dp[idx][previdx+1]!=-1)return dp[idx][previdx+1];
        int take=0;
        if(previdx==-1||pairs[idx][0]>pairs[previdx][1]){
            take=1+solve(pairs,idx+1,idx);
        }
        int skip=solve(pairs,idx+1,previdx);
        return dp[idx][previdx+1]=max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        dp.assign(n,vector<int>(n+1,-1));
        sort(pairs.begin(),pairs.end());
        
        return solve(pairs,0,-1);
    }
};