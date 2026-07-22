class Solution {
public:
    int MOD=1e9+7;
    int t[51][101][51];
    int solve(int idx,int max_value,int cost,int n,int m,int k){
        if(cost>k)return 0;
        if(idx==n) return cost==k?1:0;
        if(t[idx][max_value][cost]!=-1){
            return t[idx][max_value][cost];
        }
        int result=0;
        for(int i=1;i<=m;i++){
            if(i>max_value){
                result=(result+solve(idx+1,i,cost+1,n,m,k))%MOD;
            } else {
                result=(result+solve(idx+1,max_value,cost,n,m,k))%MOD;
            }
        }
        return t[idx][max_value][cost]=result%MOD;

    }
    int numOfArrays(int n, int m, int k) {
        if(k>m||k>n)return 0;
        memset(t,-1,sizeof(t));
        return solve(0,0,0,n,m,k);
    }
};