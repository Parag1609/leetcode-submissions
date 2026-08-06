class Solution {
public:
    

    int maxVowels(string s, int k) {
        int maxcount=0;
        int currwindowcount=0;
        int i=0,j=0,n=s.length();
        auto isVowel=[&](char ch){
            return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
        };
        while(j<n){
            if(isVowel(s[j]))currwindowcount++;
            if(j-i+1==k){
                maxcount=max(maxcount,currwindowcount);
                if (maxcount == k) return k;
                if(isVowel(s[i]))currwindowcount--;
                i++;
            }
            j++;

        }
        return maxcount;
    }
};