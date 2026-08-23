class Solution {
public:
    int maxSatisfaction(vector<int>&a) {
        int n=a.size();
        sort(a.begin(),a.end());
        int dp[501][501];
        memset(dp,0,sizeof(dp));
        // auto dfs=[&](auto& slef,int idx,int t)->int{
        //     if(idx>=n)return 0;
        //     if(dp[idx][t]!=-1)return dp[idx][t];
        //     int skip=slef(slef,idx+1,t);
        //     int taken=a[idx]*t+slef(slef,idx+1,t+1);
        //     return dp[idx][t]=max(skip,taken);
        // };
        // for(int i=0;i<501;i++){
        //     dp[n][i]=0;
        // }
        for(int idx=n-1;idx>=0;idx--){
            for(int t=n;t>=1;t--){
                dp[idx][t]=max(dp[idx+1][t],a[idx]*t+dp[idx+1][t+1]);
            }
        }
          return max(0,dp[0][1]);
        }
};