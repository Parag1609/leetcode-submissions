class Solution {
public:
    int n;
    vector<vector<int>>dp2;
    vector<vector<int>>dp3;
    int solve2(int i,int j,vector<vector<int>>& fruits){
        if(i>=n ||i<0||j<0|| j>=n)return -1e9;
        if(i==n-1 && j==n-1)return 0;
        if(j<=i)return -1e9;
       
        if(dp2[i][j]!=-1)return dp2[i][j];
        int down=solve2(i+1,j,fruits);
        int left_d=solve2(i+1,j-1,fruits);
        int right_d=solve2(i+1,j+1,fruits);

        return dp2[i][j]=fruits[i][j]+max({down,left_d,right_d});
    }
    int solve3(int i,int j,vector<vector<int>>& fruits){
        if(i>=n ||i<0||j<0|| j>=n)return -1e9;
        if(i==n-1 && j==n-1)return 0;
        if(i<=j)return -1e9;
        if(dp3[i][j]!=-1)return dp3[i][j];

        int down_d=solve3(i+1,j+1,fruits);
        int up_d=solve3(i-1,j+1,fruits);
        int right=solve3(i,j+1,fruits);

        return dp3[i][j]=fruits[i][j]+max({down_d,up_d,right});
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n=fruits.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=fruits[i][i];
        }
        dp2.assign(n,vector<int>(n,-1));
        dp3.assign(n,vector<int>(n,-1));
        ans+=solve2(0,n-1,fruits);
        ans+=solve3(n-1,0,fruits);
        return ans;

    }
};