class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        int k=n/3;
        int dp1[500][500/3];
         int dp2[500][500/3];
        memset(dp1,-1,sizeof(dp1));
                memset(dp2,-1,sizeof(dp2));

        auto dfs=[&](auto& slef,int idx,int cnt,int la,auto& dp)->int{
            if(cnt>=k)return 0;
            if(idx>la)return 0;
            if(dp[idx][cnt]!=-1)return dp[idx][cnt];
            int skip=slef(slef,idx+1,cnt,la,dp);
            int take=slices[idx]+slef(slef,idx+2,cnt+1,la,dp);
            return dp[idx][cnt]=max(skip,take);
        };
        return max(dfs(dfs,0,0,n-2,dp1),dfs(dfs,1,0,n-1,dp2));
    }
};