/* 
//brute force
class Solution {
public:
    void solve(int i,int j,string s1,string s2,string &temp,string& result){
        if(i>=s1.size()||j>=s2.size()){
            while(i<s1.size()){
                temp.push_back(s1[i++]);
            }
            while(j<s2.size()){
                temp.push_back(s2[j++]);
            }
            if(temp.size()<result.size()){
                result=temp;
            }
            return;
        }
        if(s1[i]==s2[j]){
            temp.push_back(s1[i]);
            solve(i+1,j+1,s1,s2,temp,result);
            temp.pop_back();
        }else{
            temp.push_back(s2[j]);
            solve(i,j+1,s1,s2,temp,result);
            temp.pop_back();
            temp.push_back(s1[i]);
            solve(i+1,j,s1,s2,temp,result);
            temp.pop_back();
        }
    }
    string shortestCommonSupersequence(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();

        string temp;
        string result=s1+s2;
        solve(0,0,s1,s2,temp,result);   
        return result;
    }
};
*/

class Solution {
public:
    
    string shortestCommonSupersequence(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0) dp[i][j]=i+j;

                else if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];

                else dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        int i=m;
        int j=n;
        string scs="";
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                scs.push_back(s1[i-1]);
                i--;
                j--;
            }else if(dp[i-1][j]<dp[i][j-1]){
                scs.push_back(s1[i-1]);
                i--;
            }else{
                scs.push_back(s2[j-1]);
                j--;
            }
        }
        while(i>0){
            scs.push_back(s1[i-1]);
            i--;
        }
        while(j>0){
            scs.push_back(s2[j-1]);
            j--;
        }
        reverse(scs.begin(),scs.end());
        return scs;
   
    }
};
