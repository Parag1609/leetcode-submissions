class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int count=0;
        
        int i=0,j=0;
        int sum=0;
        int countzeros=0;
        while(j<n){
            sum+=nums[j];
            while(i<=j && (sum>goal || (i<j && nums[i]==0))){
                if(nums[i]==0)countzeros++;
                else countzeros=0;
                sum-=nums[i];
                i++;
            }
            if(i<=j && sum==goal){
                count+=1+countzeros;
            }
            j++;
        }
        return count;
    }
};