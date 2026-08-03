class Solution {
public:
    int n;
    bool isSubsetSum(vector<int>& nums,int target){
        vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));

        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int t=1;t<=target;t++){
                if(nums[i-1]>t){
                    dp[i][t]=dp[i-1][t];
                }else{
                    bool include=dp[i-1][t-nums[i-1]];
                    bool exclude=dp[i-1][t];
                    dp[i][t]=include||exclude;
                }
            }
        }
        return dp[n][target];
    }
    bool canPartition(vector<int>& nums) {
        n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        int target_sum=sum/2;
        return isSubsetSum(nums,target_sum);
    }
};