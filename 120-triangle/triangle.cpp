class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        
        int dp[201][201];
        memset(dp,0x3f,sizeof(dp));

        auto dfs=[&](auto& slef,int idx1,int idx2)->int{
            if(idx1>=n || idx2>=n)return 0;

            if(dp[idx1][idx2]!=0x3f3f3f3f)
                return dp[idx1][idx2];

            int take=triangle[idx1][idx2]+slef(slef,idx1+1,idx2);
            int take1=triangle[idx1][idx2]+slef(slef,idx1+1,idx2+1);

            return dp[idx1][idx2]=min(take,take1);
        };

        return dfs(dfs,0,0);
    }
};