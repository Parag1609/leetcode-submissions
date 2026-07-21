//bottom-up
class Solution {
public:
    int longestStrChain(vector<string>& words) {
     sort(words.begin(),words.end(),[](const string& a,const string& b){
        return a.length()<b.length();
     });   
    
    vector<int>dp(words.size(),1);
    int lchain=1;
    for(int i=1;i<words.size();i++){
        for(int j=0;j<i;j++){
            string s=words[i];
            if(words[i].length()-words[j].length()>2 ||words[i].length()==words[j].length())continue;
            for(int k=0;k<s.length();k++){
                string temp=s;
                temp.erase(k,1);
                if(temp==words[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                    break;
                }
            }
        }
        lchain=max(lchain,dp[i]);
    }
        return lchain;
    }
};
/*
// memoization
class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<string>& words,int idx,int previdx){
        if(idx>=words.size())return 0;

        if(dp[idx][previdx+1]!=-1)return dp[idx][previdx+1];

        int take=0;
        if(previdx==-1|| words[idx].length()-words[previdx].length()==1){
            string s=words[idx];
            for(int k=0;k<words[idx].length();k++){
                string temp=s;
                temp.erase(k,1);
                if(previdx==-1||temp==words[previdx]){
                    take=1+solve(words,idx+1,idx);
                    break;
                }
                
            }
        }
        int skip=solve(words,idx+1,previdx);
        return dp[idx][previdx+1]=max(take,skip);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string& a,const string& b){
            return a.length()<b.length();
        });   
        int n=words.size();
        dp.assign(n,vector<int>(n+1,-1));
        return solve(words,0,-1);
    }
};
*/