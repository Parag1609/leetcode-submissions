class Solution {
public:
    vector<int>dp;
    int solve(int start,vector<int>& nums,int end){
        if(start>end)return 0;
        if(dp[start]!=-1)return dp[start];

        int steal=nums[start]+solve(start+2,nums,end);
        int skip=solve(start+1,nums,end);
        return dp[start]=max(steal,skip);

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        dp.assign(n,-1);
        int amount1=solve(0,nums,n-2);
        dp.assign(n,-1);
        int amount2=solve(1,nums,n-1);
        return max(amount1,amount2);
    }
};