class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<int>dp(pairs.size(),1);
        sort(pairs.begin(),pairs.end());
        int lchain=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
           lchain=max(lchain,dp[i]);
        }
        return lchain;
    }
};