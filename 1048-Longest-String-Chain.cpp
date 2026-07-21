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