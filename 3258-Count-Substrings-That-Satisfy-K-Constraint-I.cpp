class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int czeros=0,cones=0;
        int j=0,i=0,count=0;
        int n=s.length();

        while(j<n){
            if(s[j]=='0')czeros++;
            else cones++;
            while(czeros>k && cones>k){
                if(s[i]=='0')czeros--;
                else cones--;
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
};