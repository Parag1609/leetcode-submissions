class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalones=0;
        int n=nums.size();
        for(int num:nums){
            totalones+=num==1?1:0;
        }
        vector<int>temp(2*n);
        for(int i=0;i<2*n;i++){
            temp[i]=nums[i%n];
        }

        int i=0,minswaps=INT_MAX,currones=0;
        for(int j=0;j<2*n;j++){
            if(temp[j]==1)currones++;
            while(j-i+1>totalones){
                if(temp[i]==1)currones--;
                i++;
            }
            minswaps=min(minswaps,totalones-currones);
        }
        return minswaps;
    }
};