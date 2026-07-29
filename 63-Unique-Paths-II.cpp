/*class Solution {
public:
    vector<vector<int>>dp;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();

        dp.assign(row,vector<int>(col,0));

        for(int i=0;i<row;i++){
            if(obstacleGrid[i][0]==1)break;
            dp[i][0]=1;
        }
        for(int j=0;j<col;j++){
            if(obstacleGrid[0][j]==1)break;
            dp[0][j]=1;
        }
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(obstacleGrid[i][j]!=1)dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[row-1][col-1];
    }
};
*/
class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();

        vector<int>prev(col,0);

        
        for(int j=0;j<col;j++){
            if(obstacleGrid[0][j]==1)break;
            prev[j]=1;
        }
        for(int i=1;i<row;i++){
            vector<int>curr(col,0);
            if (obstacleGrid[i][0] == 0) {
                curr[0] = prev[0]; 
            }
            for(int j=1;j<col;j++){
                if(obstacleGrid[i][j]!=1)curr[j]=curr[j-1]+prev[j];
            }
            prev=curr;
        }
        return prev[col-1];
    }
};