/*
//recursion+memoization
class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>& nums,int idx,int previdx){
        if(idx>=nums.size())return 0;
        if(dp[idx][previdx+1]!=-1) return dp[idx][previdx+1];
        int take=0;
        if(previdx==-1||nums[idx]>nums[previdx]){
            take=1+solve(nums,idx+1,idx);
        }
        int skip=solve(nums,idx+1,previdx);
        return dp[idx][previdx+1]=max(take,skip);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,vector<int>(n+1,-1));
        return solve(nums,0,-1);
    }
};
*/
//bottom-up
class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int maxlis=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            maxlis=max(maxlis,dp[i]);
        }
       return maxlis;
    }
};