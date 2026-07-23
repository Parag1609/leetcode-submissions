/* 
//memoization
class Solution {
public:
    vector<vector<int>>dp;
    int solve(int idx1,int idx2,string& text1,string& text2){
        if(idx1>=text1.size()||idx2>=text2.size())return 0;
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];

        if(text1[idx1]==text2[idx2]){
            return 1+solve(idx1+1,idx2+1,text1,text2);
        }
        int take1=solve(idx1,idx2+1,text1,text2);
        int take2=solve(idx1+1,idx2,text1,text2);
        return dp[idx1][idx2] = max(take1,take2);

    }
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size()==0||text2.size()==0)return 0;
        dp.assign(text1.size(),vector<int>(text2.size(),-1));
        return solve(0,0,text1,text2);
    }
};
*/
//space optimized
class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        if(m==0||n==0)return 0;
        vector<int>prev(n+1,0);

        for(int i=1;i<=m;i++){
            vector<int>curr(n+1,0);
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]){
                   curr[j]=prev[j-1]+1;
                }else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[n];
    }
};