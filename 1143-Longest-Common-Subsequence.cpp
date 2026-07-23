
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