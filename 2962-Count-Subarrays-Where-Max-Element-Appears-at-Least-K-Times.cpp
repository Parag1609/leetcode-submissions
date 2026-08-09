class Solution {
public:

    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        long long count=0;
        int maxi=0;
        long long maxifreq=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }

        while(j<n){
            if(nums[j]==maxi)maxifreq++;
            while(maxifreq==k){
                if(nums[i]==maxi)maxifreq--;
                i++;
            }
            count+=i;
            j++;

        }
        return count;
    }
};