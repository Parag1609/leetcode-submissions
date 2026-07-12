class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,-1},{0,1}};
        vector<vector<int>> effort(n,vector<int>(m,INT_MAX));
        priority_queue<p ,vector<p>,greater<p>> pq;
        pq.push({0,{0,0}});
        effort[0][0]=0;
        while(!pq.empty()){
            int curr_effort=pq.top().first;
            auto node=pq.top().second;
            int r=node.first;
            int c=node.second;
            pq.pop();
            if(r==n-1 && c==m-1) return curr_effort;
            if(curr_effort> effort[r][c]) continue;
            for(auto &d:directions){
                int nr=r+d.first;
                int nc=c+d.second;
                if(nr>=0 && nr<n && nc>=0 && nc<m ){
                    int newEffort =  max(abs(heights[nr][nc]-heights[r][c]),curr_effort);
                    if(effort[nr][nc]> newEffort){
                        pq.push({newEffort,{nr,nc}});
                        effort[nr][nc]=newEffort;
                    }
                }
            }
        }
        return 0;
    }
};