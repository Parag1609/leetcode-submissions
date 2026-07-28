class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<vector<int>>& obstacleGrid,int i,int j,int row,int col){
        if(i>=row||j>=col)return 0;
        if(obstacleGrid[i][j]==1)return dp[i][j]=0;

        if(i==row-1 && j==col-1)return 1;

        if(dp[i][j]!=-1)return dp[i][j];
        
        int right=solve(obstacleGrid,i,j+1,row,col);
        int down=solve(obstacleGrid,i+1,j,row,col);
        return dp[i][j]=right+down;

        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();

        dp.assign(row,vector<int>(col,-1));
        
        return solve(obstacleGrid,0,0,row,col);


    }
};