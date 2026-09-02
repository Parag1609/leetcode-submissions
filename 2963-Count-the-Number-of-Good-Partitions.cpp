class Solution {
public:
    int M=1e9+7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int cuts=0;
        int maxlast=0;
        int n=nums.size();
        unordered_map<int,int>last;
        for(int i=0;i<n;i++){
            last[nums[i]]=i;
        }

        for(int i=0;i<n;i++){
            maxlast=max(maxlast,last[nums[i]]);

            if(maxlast==i && i!=n-1){
                cuts++;
            }
        }
        int gp=1;
        for(int i=1;i<=cuts;i++){
            gp=(gp*2)%M;
        }
        return gp;
    }
};