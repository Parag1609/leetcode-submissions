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
           if(r<n){
               s[r]=' ';
                r++;
                l=r;
           } 
          }
        }
      if (r > 0 && s[r - 1] == ' ') {
            s.erase(s.begin() + r - 1, s.end());
        } else {
            s.erase(s.begin() + r, s.end());
        }
     return s;
    }
};