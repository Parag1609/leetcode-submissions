class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalones=0;
        int n=nums.size();
        for(int num:nums){
            totalones+=num;
        }
        
        int i=0,maxones=0,currones=0;
        for(int j=0;j<2*n;j++){
            currones+=nums[j%n];
            if(j-i+1>totalones){
                currones-=nums[i%n];
                i++;
            }
            if(j - i + 1 == totalones)maxones=max(maxones,currones);
        }
        return totalones-maxones;
    }
};