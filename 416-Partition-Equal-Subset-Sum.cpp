class Solution {
public:
    int n;
    bool solveSubsetSum(int n, vector<int>& nums ,int target_sum){
        if(target_sum==0)return true;
        if(n<0)return false;

        if(nums[n]>target_sum){
            return solveSubsetSum(n-1,nums,target_sum);
        }
        bool take=solveSubsetSum(n-1,nums,target_sum-nums[n]);
        bool skip=solveSubsetSum(n-1,nums,target_sum);
        return take||skip;
    }
    bool canPartition(vector<int>& nums) {
        n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        int target_sum=sum/2;

        return solveSubsetSum(n-1,nums,target_sum);
    }
};