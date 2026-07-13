class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        map<pair<int,int>,vector<vector<int>>>adj;
        map<pair<int,int>,bool>inMst;
        for(auto & point:points){
            int x=point[0];
            int y=point[1];
            inMst[{x,y}]=false;
            for(auto & p:points){
                int x_=p[0];
                int y_=p[1];
                int dist=abs(x-x_)+abs(y-y_);
                adj[{x,y}].push_back({x_,y_,dist});
                adj[{x_,y_}].push_back({x,y,dist});
            }
        }
        priority_queue<p,vector<p>,greater<p>>pq;
        auto & c=points[0];
        pq.push({0,{c[0],c[1]}});
        int cost=0;
        while(!pq.empty()){
            auto & a=pq.top();
            pq.pop();
            int weight=a.first;
            auto & coord=a.second;
            int x=coord.first;
            int y=coord.second;
            if(inMst[coord]) continue;
            inMst[coord]=true;
            cost+=weight;
            for(auto & b:adj[coord]){
                int x_=b[0];
                int y_=b[1];
                int dist=b[2];
                if(!inMst[{x_,y_}]){
                    pq.push({dist,{x_,y_}});
                }
            }
        }

     return cost;
    }
};