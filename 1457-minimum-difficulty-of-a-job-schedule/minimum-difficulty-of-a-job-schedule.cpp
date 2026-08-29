class Solution{
public:
    int minDifficulty(vector<int>& jobDifficulty,int d){
        int n=jobDifficulty.size();
        if(n<d)return -1;

        int dp[301][11];
        memset(dp,-1,sizeof(dp));

        auto dfs=[&](auto& slef,int idx,int gr)->int{
            if(idx>=n){
                if(gr==d)return 0;
                return 1e9;
            }

            if(gr==d)return 1e9;

            if(dp[idx][gr]!=-1)
                return dp[idx][gr];

            int ans=1e9;
            int mx=0;

            for(int i=idx;i<n;i++){
                mx=max(mx,jobDifficulty[i]);

                int nxt=slef(slef,i+1,gr+1);

                ans=min(ans,mx+nxt);
            }

            return dp[idx][gr]=ans;
        };

        return dfs(dfs,0,0);
    }
};