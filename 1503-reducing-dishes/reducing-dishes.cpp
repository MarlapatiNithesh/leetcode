class Solution {
public:
    int maxSatisfaction(vector<int>&a) {
        int n=a.size();
        sort(a.begin(),a.end());
        int dp[501][501];
        memset(dp,-1,sizeof(dp));
        auto dfs=[&](auto& slef,int idx,int t)->int{
            if(idx>=n)return 0;
            if(dp[idx][t]!=-1)return dp[idx][t];
            int skip=slef(slef,idx+1,t);
            int taken=a[idx]*t+slef(slef,idx+1,t+1);
            return dp[idx][t]=max(skip,taken);
        };
        return max(0,dfs(dfs,0,1));
    }
};