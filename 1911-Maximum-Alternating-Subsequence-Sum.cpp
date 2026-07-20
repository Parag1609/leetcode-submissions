/*
//recursion+memoization
class Solution {
public:
    vector<vector<long long>>dp;
    long long solve(int idx,bool isEven,vector<int>& nums){
        if(idx>=nums.size())return 0;

        if(dp[idx][isEven]!=-1) return dp[idx][isEven];

        long long skip = solve(idx+1,isEven,nums);
        long long take = 0;
        if(isEven){
            take = nums[idx] + solve(idx+1,false,nums);  
        }
        else{
            take = -nums[idx] + solve(idx+1,true,nums);   
        }
        return dp[idx][isEven]=max(take,skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,vector<long long>(2,-1));
        return solve(0,true,nums);
    }
};

class Solution {
public:
    //bottom-up
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        
        dp[0][0]=nums[0];
        dp[0][1]=0;

        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+nums[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-nums[i]);
        }
        return dp[n-1][0];
    }
};
*/
class Solution {
public:
    //constant-space
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        
        long long maxeven=nums[0];
        long long maxodd=0;

        for(int i=1;i<n;i++){
            long long nexteven=max(maxeven,maxodd+nums[i]);
            long long nextodd=max(maxodd,maxeven-nums[i]);

            maxeven=nexteven;
            maxodd=nextodd;
        }
        return maxeven;
    }
};