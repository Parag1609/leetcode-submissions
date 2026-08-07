class Solution {
public:
    int characterReplacement(string s, int k) {
       int left=0,right=0;
       int maxlen=0,maxfreq=0;
       vector<int> mp(26, 0);
       int n=s.size();
       while(right<n){
            mp[s[right]-'A']++;
           
            maxfreq=max(maxfreq,mp[s[right]-'A']);
            
            if(right-left+1 - maxfreq >k){
                mp[s[left]-'A']--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
            right++;
       }
       return maxlen;
    }
};