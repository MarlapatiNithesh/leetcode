class Solution{
public:
    int splitArray(vector<int>& nums,int k){
        int n=nums.size();
        int dp[1001][51];
        memset(dp,-1,sizeof(dp));

        auto dfs=[&](auto& slef,int idx,int gr)->int{
            if(idx>=n){
                if(gr==k)return 0;
                return 1e9;
            }

            if(gr==k)return 1e9;

            if(dp[idx][gr]!=-1)
                return dp[idx][gr];

            int ans=1e9;
            int sum=0;

            for(int i=idx;i<n;i++){
                sum+=nums[i];

                int nxt=slef(slef,i+1,gr+1);

                ans=min(ans,max(sum,nxt));
            }

            return dp[idx][gr]=ans;
        };

        return dfs(dfs,0,0);
    }
};