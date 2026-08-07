class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>average(n,-1);
        int i=0,j=0;
        long long currwindowsum=0;
        while(j<n){
            currwindowsum+=nums[j];
            if(j-i+1==2*k+1){
                long long avg=currwindowsum/(2*k+1);
                average[i+k]=avg;
                currwindowsum-=nums[i];
                i++;
            }
            j++;
        }
        return average;
    }
};