class Solution {
public:
    vector<vector<int>>dp;
    vector<vector<string>>result;
    void computegrid(string& s,int n){
        for(int l=1;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(i==j)dp[i][j]=true;
                else if(s[i]==s[j]){
                    if(l==2)dp[i][j]=true;
                    else dp[i][j]=dp[i+1][j-1];
                }
            }
        }
    }
    void solve(string& s,int i,vector<string>&currlist){
        if(i==s.size()){
            result.push_back(currlist);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(dp[i][j]){
                currlist.push_back(s.substr(i,j-i+1));
                solve(s,j+1,currlist);
                currlist.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        dp.assign(n,vector<int>(n,0));
        result.clear();
        computegrid(s,n);

        vector<string>currlist;
        solve(s,0,currlist);
        return result;
    }
};