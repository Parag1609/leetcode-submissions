class Solution {
public:
    int M=1e9+7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int cuts=0;
       
        int n=nums.size();
        int result=1;
        unordered_map<int,int>last;
        for(int i=0;i<n;i++){
            last[nums[i]]=i;
        }
        int j=max(0,last[nums[0]]);
        for(int i=0;i<n;i++){
            if(i>j){
                result=(result*2)%M;
            }
            j=max(j,last[nums[i]]);
        }
        return result;
    }
};