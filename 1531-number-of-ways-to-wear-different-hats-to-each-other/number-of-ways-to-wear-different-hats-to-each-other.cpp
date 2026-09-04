class Solution {
public:
   static const int MOD=1e9+7;
    int numberWays(vector<vector<int>>& hats) {
        int n=hats.size();
        vector<int>nwHats[41];
        for(int i=0;i<hats.size();i++){
            for(auto it:hats[i]){
                nwHats[it].push_back(i);
            }
        }
        int dp[41][1<<n];
        memset(dp,-1,sizeof(dp));
        int done=(1<<n)-1;
        auto dfs=[&](auto& slef,int idx,int mask)->int{
            if(done==mask)return 1;
            if(idx>40)return 0;
            if(dp[idx][mask]!=-1)return dp[idx][mask];
            int ans=0;
                ans+=slef(slef,idx+1,mask);
                ans%=MOD;
            for(auto pe:nwHats[idx]){
                if(mask&(1<<pe))continue;
                ans+=slef(slef,idx+1,mask|(1<<pe));
                ans%=MOD;
            }
            
            return dp[idx][mask]=ans%MOD;
        };
        return dfs(dfs,1,0);
    }
};