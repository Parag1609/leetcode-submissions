class Solution {
public:
    int n;
    vector<vector<int>>dp;
    bool solveSubsetSum(int n, vector<int>& nums ,int target_sum){
        if(target_sum==0)return true;
        if(n<0)return false;
        if(dp[n][target_sum]!=-1)return dp[n][target_sum];
        if(nums[n]>target_sum){
            return dp[n][target_sum]=solveSubsetSum(n-1,nums,target_sum);
        }
        bool take=solveSubsetSum(n-1,nums,target_sum-nums[n]);
        bool skip=solveSubsetSum(n-1,nums,target_sum);
        return dp[n][target_sum]=take||skip;
    }
    bool canPartition(vector<int>& nums) {
        n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        int target_sum=sum/2;
        dp.assign(n,vector<int>(target_sum+1,-1));
        return solveSubsetSum(n-1,nums,target_sum);
    }
};