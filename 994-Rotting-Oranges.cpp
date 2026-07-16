class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int freshcount=0;
        queue<pair<pair<int,int>,int>>que;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==1) freshcount ++;
                else if(grid[r][c]==2) que.push({{r,c},0});
            }
        }
        if (freshcount==0) return 0;
        vector<pair<int,int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
        int minutesElapsed=0;
        while(!que.empty()){
            int r=que.front().first.first;
            int c=que.front().first.second;
            int currentMinutes=que.front().second;
            que.pop();
            minutesElapsed=max(currentMinutes,minutesElapsed);
            for(auto & dir:directions){
                int nr= r+dir.first;
                int nc= c+dir.second;
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    freshcount--;
                    que.push({{nr,nc},currentMinutes+1});
                }
            }
        }
        
        return (freshcount!=0?-1:minutesElapsed);
    }
};