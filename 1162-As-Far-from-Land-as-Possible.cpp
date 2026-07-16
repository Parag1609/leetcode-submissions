class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<pair<int,int>,int>>que;
        int watercount=0;
        int landcount=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==1){
                    que.push({{r,c},0});
                    landcount++;
                }
                else watercount++;
            }
        }
        if(watercount==0 || landcount==0)return -1;
        vector<pair<int,int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
        int maxdist=0;
        while(!que.empty()){
            int r=que.front().first.first;
            int c=que.front().first.second;
            int currmindist=que.front().second;
            que.pop();
            maxdist=max(currmindist,maxdist);
            for(auto & dir:directions){
                int nr=r+dir.first;
                int nc=c+dir.second;
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0){
                    grid[nr][nc]=1;
                    que.push({{nr,nc},currmindist+1});
                }
            }
        }
        return maxdist;
    }
};