class Solution {
public:
    int m,n;
    vector<vector<int>>dp;
    int solve(int i,int j,vector<vector<int>>& grid){
        if(i>=m || j>=n)return 1e9;
        if(i==m-1 && j==n-1)return dp[i][j]=grid[i][j];

        if(dp[i][j]!=-1)return dp[i][j];

        int right=grid[i][j]+solve(i,j+1,grid);
        int down=grid[i][j]+solve(i+1,j,grid);
        return dp[i][j]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int pathsum=0;
        dp.assign(m,vector<int>(n,-1));
        return solve(0,0,grid);
    }
};