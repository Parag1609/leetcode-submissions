class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalones=0;
        int n=nums.size();
        for(int num:nums){
            totalones+=num==1?1:0;
        }
        
        int i=0,minswaps=INT_MAX,currones=0;
        for(int j=0;j<2*n;j++){
            if(nums[j%n]==1)currones++;
            if(j-i+1>totalones){
                if(nums[i%n]==1)currones--;
                i++;
            }
            minswaps=min(minswaps,totalones-currones);
        }
        return minswaps;
    }
};