class Solution {
public:
    int m,n;
    typedef long long ll;
    int MOD=1e9+7;
    vector<vector<pair<ll,ll>>>dp;
    /*pair<ll,ll> solve(int i,int j,vector<vector<int>>& grid){
        int val=grid[i][j];
        if(i==m-1 && j==n-1)return {val,val};
        if(dp[i][j]!= pair<ll, ll>{LLONG_MAX,LLONG_MIN} )return dp[i][j];
        else if(i==m-1){
            auto right=solve(i,j+1,grid);
            return dp[i][j]= {min(val*right.first,val*right.second),max(val*right.first,val*right.second)};
        }
        else if(j==n-1){
            auto down=solve(i+1,j,grid);
            return dp[i][j]={min(val*down.first,val*down.second),max(val*down.first,val*down.second)};
        }

        auto down=solve(i+1,j,grid);
        auto right=solve(i,j+1,grid);
        
        ll p1=grid[i][j]*down.first;
        ll p2=grid[i][j]*down.second;
        ll p3=grid[i][j]*right.first;
        ll p4=grid[i][j]*right.second;
       
        ll minval=min({p1,p2,p3,p4});
        ll maxval=max({p1,p2,p3,p4});
    
        return dp[i][j]={minval,maxval};
    }*/
    int maxProductPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        dp.assign(m,vector<pair<ll,ll>>(n,{0,0}));
        
        dp[0][0]={grid[0][0],grid[0][0]};
        for(int j=1;j<n;j++){
            ll p=grid[0][j]*dp[0][j-1].first;
            dp[0][j]={p,p};
        }
        for(int i=1;i<m;i++){
            ll p=grid[i][0]*dp[i-1][0].first;
            dp[i][0]={p,p};
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                ll p1=grid[i][j]*dp[i][j-1].first;
                ll p2=grid[i][j]*dp[i][j-1].second;
                ll p3=grid[i][j]*dp[i-1][j].first;
                ll p4=grid[i][j]*dp[i-1][j].second;
                dp[i][j]={min({p1,p2,p3,p4}),max({p1,p2,p3,p4})};
            }
        }
        return dp[m-1][n-1].second<0?-1:dp[m-1][n-1].second %MOD;
    }
};