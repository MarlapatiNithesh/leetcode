class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        int dp[101][201];
        memset(dp,-1,sizeof(dp));
        static const int MOD=1e9+7;

        auto dfs=[&](auto& slef,int idx,int cur)->int{
            if(cur<0)return 0;

            if(dp[idx][cur]!=-1)return dp[idx][cur];

            int ans=0;

            if(idx==finish)ans=1;

            for(int i=0;i<n;i++){
                if(i==idx)continue;

                int nw_curr=cur-abs(locations[idx]-locations[i]);

                if(nw_curr>=0){
                    ans=(ans+slef(slef,i,nw_curr))%MOD;
                }
            }

            return dp[idx][cur]=ans;
        };

        return dfs(dfs,start,fuel);
    }
};