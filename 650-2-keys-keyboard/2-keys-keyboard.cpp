class Solution {
public:
    int minSteps(int n) {
        vector<vector<int>>dp(1001,vector<int>(2,-1));
        auto dfs=[&](auto& slef,int prev,int tt,int la)->int{
            if(tt==n)return 0;
            if(dp[prev][la]!=-1)return dp[prev][la];
            int cp=1e9,pa=1e9;
            if(la){
                cp=1+slef(slef,tt,tt,0);
            }
            if(prev>0&&tt+prev<=n){
                pa=1+slef(slef,prev,tt+prev,1);
            }

            return dp[prev][la]=min(cp,pa);
        };

        return dfs(dfs,0,1,1);
    }
};