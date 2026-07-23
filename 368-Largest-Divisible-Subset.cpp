/*
//recursion
class Solution {
public:
    void solve(vector<int>& nums,int idx,vector<int>& result,vector<int>&temp,int prev){
        if(idx>=nums.size()){
            if(temp.size()>result.size()){
                result=temp;
            }
            return;
        }
        //take
        if(prev==-1||nums[idx]%prev==0){
            temp.push_back(nums[idx]);//take
            solve(nums,idx+1,result,temp,nums[idx]);
            temp.pop_back();
        }
        //skip
        solve(nums,idx+1,result,temp,prev);     

    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<int>result;
        vector<int>temp;
        int prev=-1;
        solve(nums,0,result,temp,prev);
        return result;
    }
};
*/
//bottom up
class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<int>dp(nums.size(),1);
        vector<int>prev_idx(nums.size(),-1);
        int maxlenidx=0;

        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(1+dp[j]>dp[i]) prev_idx[i]=j;
                    dp[i]=max(dp[i],1+dp[j]);
                    maxlenidx=dp[i]>dp[maxlenidx]?i:maxlenidx;
                }
            }
        } 
        vector<int>result;
        int idx=maxlenidx;
        while(idx!=-1){
            result.push_back(nums[idx]);
            idx=prev_idx[idx];
        }
        return result;
    }
};