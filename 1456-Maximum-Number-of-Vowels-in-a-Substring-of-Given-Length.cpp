class Solution {
public:
    bool isVowel(char ch){
        if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')return true;
        return false;
    }

    int maxVowels(string s, int k) {
        int maxcount=0;
        int currwindowcount=0;
        int i=0,j=0,n=s.length();
        while(j<n){
            if(isVowel(s[j]))currwindowcount++;
            if(j-i+1==k){
                maxcount=max(maxcount,currwindowcount);
                if(isVowel(s[i]))currwindowcount--;
                i++;
            }
            j++;

        }
        return maxcount;
    }
};