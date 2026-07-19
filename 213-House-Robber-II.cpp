class Solution {
public:
    int robLinear(int start,vector<int>& nums,int end){
       int prev2=0;
       int prev1=0;
       for(int i=start;i<=end;i++){
        int current=max(nums[i]+prev2,prev1);
        prev2=prev1;
        prev1=current;
       }
       return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
    
        int amount1=robLinear(0,nums,n-2);
  
        int amount2=robLinear(1,nums,n-1);
        return max(amount1,amount2);
    }
};