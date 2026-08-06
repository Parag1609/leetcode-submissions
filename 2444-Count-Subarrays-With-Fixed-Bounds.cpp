class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int minkpos=-1;
        int maxkpos=-1;
        int culpritidx=-1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK||nums[i]>maxK){
                culpritidx=i;
            }
            if(nums[i]==maxK){
                maxkpos=i;
            }
            if(nums[i]==minK){
                minkpos=i;
            }
            int smaller=min(minkpos,maxkpos);
            ans+= max(0,smaller-culpritidx);
            
        }
        return ans;
    }
};