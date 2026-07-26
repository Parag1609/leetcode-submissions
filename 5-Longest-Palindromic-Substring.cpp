class Solution {
public:
    vector<vector<int>>dp;
    bool solve(string& s,int i,int j){
        if(i>=j) return dp[i][j]=true;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j])return solve(s,i+1,j-1);

        return dp[i][j]=false;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int maxlen=0;
        int startidx=-1;
        dp.assign(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)&&j-i+1>maxlen){
                    maxlen=j-i+1;
                    startidx=i;
                }
            }
        }
        return s.substr(startidx,maxlen);
    }
};