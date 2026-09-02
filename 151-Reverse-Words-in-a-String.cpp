class Solution {
public:
    
    string reverseWords(string s) {
        int n=s.length();
        reverse(s.begin(),s.end());
        int l=0,r=0;
        for(int i=0;i<n;i++){
          while(i<n && s[i]!=' '){
            s[r++]=s[i++];
          }
          if(l<r){
            reverse(s.begin()+l,s.begin()+r);
            s[r]=' ';
            r++;
            l=r;
          }
        }
     s.erase(s.begin()+r-1,s.end());
     return s;
    }
};