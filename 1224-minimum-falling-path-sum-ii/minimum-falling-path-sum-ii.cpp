class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        int dp[201][202];
        fill(&dp[0][0],&dp[0][0]+201*201,1e9);

        auto dfs=[&](auto& slef,int idx1,int prev)->int{
            if(idx1>=n)return 0;

            if(dp[idx1][prev+1]!=1e9)
                return dp[idx1][prev+1];

            int ans=1e9;

            for(int i=0;i<m;i++){
                if(i==prev)continue;

                ans=min(ans,grid[idx1][i]+slef(slef,idx1+1,i));
            }

            return dp[idx1][prev+1]=ans;
        };

        return dfs(dfs,0,-1);
    }
};