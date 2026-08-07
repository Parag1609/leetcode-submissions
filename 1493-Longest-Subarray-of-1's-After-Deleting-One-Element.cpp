class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int zcount=0;
        long long max1s=0;
        long long left=0,right=0;
        while(right<n){
            if(nums[right]==0)zcount++;
            while(zcount>1){
                if(nums[left]==0)zcount--;
                left++;
            }
            max1s=max(max1s,right-left+1);
            right++;
        }
        return max1s-1;
    }
};