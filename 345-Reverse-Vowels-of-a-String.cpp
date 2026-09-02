class Solution {
public:
    bool isVowel(char c){
        char l=tolower(c);
        return l=='a'||l=='e'||l=='i'||l=='o'||l=='u';
    }
    string reverseVowels(string s) {
        int l=s.length();
        int i=0,j=l-1;

        while(i<j){
            while(i<j && !isVowel(s[i]))i++;
            while(i<j && !isVowel(s[j]))j--;
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
};