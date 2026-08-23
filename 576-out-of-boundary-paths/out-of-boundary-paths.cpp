class Solution {
public:
    static const int MOD=1e9+7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int dp[52][52][52];
        memset(dp,-1,sizeof(dp));
        auto dfs=[&](auto& slef,int i,int j,int mv)->int{
            if(i<0 || j<0 || i>=m || j>=n)return 1;
            if(mv==0)return 0;
            if(dp[i+1][j+1][mv]!=-1)return dp[i+1][j+1][mv];
            int ans=0;
            ans=(ans+slef(slef,i-1,j,mv-1))%MOD;
            ans=(ans+slef(slef,i+1,j,mv-1))%MOD;
            ans=(ans+slef(slef,i,j-1,mv-1))%MOD;
            ans=(ans+slef(slef,i,j+1,mv-1))%MOD;
            return dp[i+1][j+1][mv]=ans;
        };
        return dfs(dfs,startRow,startColumn,maxMove);
    }
};