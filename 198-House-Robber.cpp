/*class Solution {
public:
    vector<int>dp;
    int solve(vector<int>& nums,int i,int n){
        if(i>=n)return 0;

        if(dp[i]!=-1)return dp[i];
        int steal =nums[i]+solve(nums,i+2,n);
        int skip=solve(nums,i+1,n);
        return dp[i]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,-1);
        return solve(nums,0,n);
    }
};
*/
class Solution {
public:
   
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        if(n==1){
            return nums[n-1];
        }
        int prev2=nums[0];
        int prev1=max(nums[1],nums[0]);
        
        for(int i=2;i<n;i++){
            int current=max(nums[i]+prev2,prev1);
            
            prev2=prev1;
            prev1=current;
        }
        return prev1;

    }
};