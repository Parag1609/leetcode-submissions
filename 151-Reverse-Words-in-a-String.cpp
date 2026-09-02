class Solution {
public:
    
    string reverseWords(string s) {
        int l=s.length();
        reverse(s.begin(),s.end());
        int storeidx=0;
        for(int i=0;i<l;i++){
          if(s[i]!=' '){

            if(storeidx!=0){
                s[storeidx++]=' ';
            }
            int j=i;
            while(j<l && s[j]!=' '){
                s[storeidx++]=s[j++];
            }
            reverse(s.begin()+storeidx-(j-i),s.begin()+storeidx);
            i=j;
          }
        }
     s.erase(s.begin()+storeidx,s.end());
     return s;
    }
};