class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();

        deque<pair<int,int>>deq;
        vector<pair<int,int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0]=grid[0][0];
        deq.push_back({0,0});

        while(!deq.empty()){
            auto [r,c]=deq.front();
            int currdist=dist[r][c];
            deq.pop_front();
            
            if(r==m-1 && c==n-1) break;

            for(auto & dir:directions){
                int nr=r+dir.first;
                int nc=c+dir.second;
                
                if(nr>=0 && nr<m && nc>=0 && nc<n ){
                    int weight=grid[nr][nc];
                    if(currdist+weight <dist[nr][nc]){
                        dist[nr][nc]=currdist+weight;

                        if(grid[nr][nc]==0) deq.push_front({nr,nc});
                        else deq.push_back({nr,nc});

                    }  
                }
            }
        }
        int minDamageTaken=dist[m-1][n-1];
        return health-minDamageTaken>=1;
    }
};