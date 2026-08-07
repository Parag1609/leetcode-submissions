class Solution {
public:
    int longestOnes(vector<int>& nums,int k) {
        int n=nums.size();
        int zcount=0;
        int max1s=0;
        int left=0,right=0;
        while(right<n){
            if(nums[right]==0)zcount++;
            while(zcount>k){
                if(nums[left]==0)zcount--;
                left++;
            }
            max1s=max(max1s,right-left+1);
            right++;
        }
        return max1s;
    }
};