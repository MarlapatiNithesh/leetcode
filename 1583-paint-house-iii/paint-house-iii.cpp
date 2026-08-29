class Solution{
public:
    int minCost(vector<int>& houses,vector<vector<int>>& cost,int m,int n,int target){
        int dp[101][22][101];
        memset(dp,-1,sizeof(dp));

        auto dfs=[&](auto& slef,int idx,int prev,int nei)->int{
            if(idx>=m){
                if(nei==target)return 0;
                return INT_MAX;
            }

            if(nei>target)return INT_MAX;

            if(dp[idx][prev+1][nei]!=-1)
                return dp[idx][prev+1][nei];

            int ans=INT_MAX;
            int s=0,nxt;

            if(houses[idx]){
                if(prev==houses[idx]){
                    nxt=slef(slef,idx+1,houses[idx],nei);
                }else{
                    nxt=slef(slef,idx+1,houses[idx],nei+1);
                }

                ans=nxt;
            }else{
                for(int i=1;i<=n;i++){
                    s=cost[idx][i-1];

                    if(prev==i){
                        nxt=slef(slef,idx+1,i,nei);
                    }else{
                        nxt=slef(slef,idx+1,i,nei+1);
                    }

                    if(nxt!=INT_MAX)
                        ans=min(ans,s+nxt);
                }
            }

            return dp[idx][prev+1][nei]=ans;
        };

        int ans=dfs(dfs,0,-1,0);

        if(ans==INT_MAX)return -1;
        return ans;
    }
};