class Solution {
public:
    int atMostKDistinct(vector<int>& nums, int k){
        if(k==0)return 0;
        int n=nums.size();
        int i=0,j=0,diffcount=0;
        int countsubarray=0;
        unordered_map<int,int>mp;
        while(j<n){
            if(mp[nums[j]]==0)diffcount++;
            mp[nums[j]]++;
            while(diffcount>k){
                if(mp[nums[i]]==1){
                    diffcount--;
                }
                mp[nums[i]]--;
                i++;
            }
            countsubarray+=j-i+1;
            j++;
        }
        return countsubarray;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return atMostKDistinct(nums,k)-atMostKDistinct(nums,k-1);
    }
};