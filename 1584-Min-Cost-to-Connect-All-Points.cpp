class Solution {
public:
    typedef pair<int,int> p;
    int primsAlgo(vector<vector<p>>& adj,int V){
        vector<bool>inMst(V,false);
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int wt=p.first;
            int node=p.second;

            if(inMst[node]) continue;
            inMst[node]=true;
            sum+=wt;

            for(auto & tmp:adj[node]){
                int neigh=tmp.first;
                int neigh_wt=tmp.second;
                if(!inMst[neigh]){
                    pq.push({neigh_wt,neigh});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<p>>adj(n);
        vector<bool>inMst(n,false);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];

                int d=abs(x2-x1)+abs(y2-y1);

                adj[i].push_back({j,d});
                adj[j].push_back({i,d});
            }
        }
        return primsAlgo(adj,n);
    }
};