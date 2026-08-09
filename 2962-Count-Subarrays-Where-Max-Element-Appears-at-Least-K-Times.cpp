class Solution {
public:
    long long atMost(vector<int>& nums, int k,int n){
        long long maxi=0;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
        }

        int i=0,j=0;
        long long count=0,maxifreq=0;

        while(j<n){
            if(nums[j]==maxi)maxifreq++;
            while(maxifreq>k){
                if(nums[i]==maxi)maxifreq--;
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        return 1LL*n*(n+1)/2 - atMost(nums,k-1,n);
    }
};