class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        vector<vector<int>>adj1(n);
        vector<vector<int>>adj2(m);

        for(auto &edge:edges1){
            int u=edge[0];
            int v=edge[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(auto &edge:edges2){
            int u=edge[0];
            int v=edge[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        auto [farthestNode1,_]=diameter(adj1,0);
        auto [_,diameter1]=diameter(adj1,farthestNode1);

        auto [farthestNode2,_]=diameter(adj2,0);
        auto [_,diameter2]=diameter(adj2,farthestNode2);

        int dia1half=(diameter1+1)/2;
        int dia2half=(diameter2+1)/2;
        int merge_dia= dia1half+dia2half+1;
        return max(max(diameter1,diameter2),merge_dia);
    }
    pair<int,int> diameter(vector<vector<int>>&adj,int source){
        int dia=0;
        int farthestNode;
        int V=adj.size();
        queue<int>que;
        vector<bool>visited(V,false);
        que.push(source);
        visited[source]=true;

        while(!que.empty()){
            int sz=que.size();
            while(sz--){
                farthestNode=que.front();
                que.pop();
                for(int v:adj[farthestNode]){
                    if(!visited[v]){
                        que.push(v);
                        visited[v]=true;
                    }
                }
            }
            dia++;
        }
        return {farthestNode,dia-1};
    }
};