/*class Solution {
public:
    int m,n;
    bool canSurvive(int i,int j,int mid,vector<vector<int>>& dungeon){
        if(i>=m || j>=n)return false;

        mid+=dungeon[i][j];
        if(mid<=0)return false;
        if(i==m-1 && j==n-1)return true;
        return canSurvive(i,j+1,mid,dungeon) || canSurvive(i+1,j,mid,dungeon);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m=dungeon.size();
        n=dungeon[0].size();

        int left=1;
        int right=4*1e7;

        int minhealth=4*1e7;

        while(left<=right){
            int mid=left + (right-left)/2;

            if(canSurvive(0,0,mid,dungeon)){
                minhealth=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
    return minhealth;

    }
};
class Solution {
public:
    int m,n;
    vector<vector<int>>dp;
    int solve(int i,int j,vector<vector<int>>& dungeon){
        if(i>=m || j>=n)return 1e9;
        if(i==m-1 && j==n-1){
            return dp[i][j]= max(1,1-dungeon[i][j]);
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int down=solve(i+1,j,dungeon);
        int right=solve(i,j+1,dungeon);
        int next_hp_required=min(down,right);

        int curr_hp_required=next_hp_required - dungeon[i][j];
        return dp[i][j]=max(1,curr_hp_required);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m=dungeon.size();
        n=dungeon[0].size();
        dp.assign(m,vector<int>(n,-1));
        return solve(0,0,dungeon);
       
    }
};
*/
class Solution {
public:
    int m,n;
    vector<vector<int>>dp;
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m=dungeon.size();
        n=dungeon[0].size();
        dp.assign(m+1,vector<int>(n+1,1e9));
        
        dp[m-1][n]=1;
        dp[m][n-1]=1;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int next_hp_req=min(dp[i+1][j],dp[i][j+1]);
                dp[i][j]=max(1,next_hp_req-dungeon[i][j]);
            }
        }
       return dp[0][0];
    }
};