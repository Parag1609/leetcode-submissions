class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        queue<pair<pair<int,int>,int>>que;
        vector<vector<int>> heights(m,vector<int>(n,0));
        vector<pair<int,int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(isWater[r][c]==1) que.push({{r,c},0});
            }
        }
        while(!que.empty()){
            int r=que.front().first.first;
            int c=que.front().first.second;
            int currheight=que.front().second;
            que.pop();
            for(auto & dir:directions){
                int nr=r+dir.first;
                int nc=c+dir.second;
                if(nr>=0 && nr<m && nc>=0 && nc<n && isWater[nr][nc]==0){
                    isWater[nr][nc]=1;
                    que.push({{nr,nc},currheight+1});
                    heights[nr][nc]=currheight+1;
                }
            }
        }
        return heights;
    }
};