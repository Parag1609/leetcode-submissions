class Solution {
public:
    typedef pair<int,int> p;
     vector<int>parent;
    vector<int>rank;
    
    int find(int i){
        if(parent[i]==i)return i;
        return parent[i]=find(parent[i]);
    }
    void    Union(int x,int y){
        int p1=find(x);
        int p2=find(y);
        if(p1==p2)return;
        if(rank[p1]<rank[p2]){
            parent[p1]=p2;
        }
        else if(rank[p1]>rank[p2]){
            parent[p2]=p1;
        }
        else{
            parent[p1]=p2;
            rank[p2]++;
        }
        return;
    }
    int kruskalAlgo(vector<vector<int>>& edges,int V){
        parent.resize(V);
        rank.resize(V,0);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        int sum=0;
        for(auto & edge:edges ){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            int p1=find(u);
            int p2=find(v);
            if(p1!=p2){
                Union(u,v);
                sum+=w;
            }
        }
        return sum;
    }
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
        vector<vector<int>>edges;
        vector<bool>inMst(n,false);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];

                int d=abs(x2-x1)+abs(y2-y1);

                edges.push_back({i,j,d});
                
            }
        }
        auto comparator=[&](vector<int>&vec1,vector<int>&vec2){
            return vec1[2]<vec2[2];
        };
        sort(begin(edges),end(edges),comparator);
        return kruskalAlgo(edges,n);
    }
};