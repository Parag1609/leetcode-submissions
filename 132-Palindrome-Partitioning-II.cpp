class Solution {
public:
    vector<vector<int>>isPalindrome;
    vector<int>mincut;
    void precomputegrid(string & s,int n){
        for(int l=1;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(i==j)isPalindrome[i][j]=true;
                else if (s[i] == s[j]) {
                    isPalindrome[i][j] = (i + 1 == j || isPalindrome[i + 1][j - 1]);
                }
            }
        }
    }
    int solve(string & s,int i,int n){
        
        for(int i=0;i<n;i++){
            if(isPalindrome[0][i])mincut[i]=0;
            else{
                for(int j=0;j<i;j++){
                    if(isPalindrome[j+1][i])mincut[i]=min(1+mincut[j],mincut[i]);
                }
            }
            
        }
        return mincut[n-1];
    }
    int minCut(string s) {
        int n=s.size();
        if(n<=1)return 0;
        isPalindrome.assign(n,vector<int>(n,0));
        precomputegrid(s,n);
        mincut.assign(n,INT_MAX);
        mincut[0]=0;
        return solve(s,0,n);
    }
};