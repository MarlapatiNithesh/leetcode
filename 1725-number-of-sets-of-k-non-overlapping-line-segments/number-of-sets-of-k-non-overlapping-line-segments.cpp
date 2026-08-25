class Solution{
public:
    static const int MOD=1e9+7;
    int numberOfSets(int n,int k){
        int dp[1001][1001][2];
        fill(&dp[0][0][0],&dp[0][0][0]+1001*1001*2,-1);
        auto dfs=[&](auto& slef,int st,int cnt,int tk)->int{
            if(cnt==k&&tk==0)return 1;
            if(st>=n)return 0;
            if(dp[st][cnt][tk]!=-1)return dp[st][cnt][tk];
            int ans=0;
            if(tk==0){
                ans=(ans+slef(slef,st+1,cnt,0))%MOD;
                if(cnt<k){
                    ans=(ans+slef(slef,st+1,cnt,1))%MOD;
                }
            }else{
                ans=(ans+slef(slef,st+1,cnt,1))%MOD;
                ans=(ans+slef(slef,st,cnt+1,0))%MOD;
            }
            return dp[st][cnt][tk]=ans;
        };
        return dfs(dfs,0,0,0);
    }
};