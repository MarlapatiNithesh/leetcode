class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size();
        int m = cost[0].size();
        int done = (1 << m) - 1;
        int dp[13][13][done+1][2];
        memset(dp,-1,sizeof(dp));
        auto dfs = [&](auto& self, int idx1, int idx2,
                       int mask, int connected) -> int {

            if(idx1 >= n) {
                if(mask == done)
                    return 0;

                return INT_MAX;
            }

            if(idx2 >= m) {
                if(connected == 0)
                    return INT_MAX;

                return self(self, idx1 + 1, 0, mask, 0);
            }
            if(dp[idx1][idx2][mask][connected]!=-1){
                return dp[idx1][idx2][mask][connected];
            }

            int nt = self(
                self,
                idx1,
                idx2 + 1,
                mask,
                connected
            );

            int temp = self(
                self,
                idx1,
                idx2 + 1,
                mask | (1 << idx2),
                1
            );

            int tt = INT_MAX;

            if(temp != INT_MAX) {
                tt = cost[idx1][idx2] + temp;
            }

            return dp[idx1][idx2][mask][connected]=min(nt, tt);
        };

        return dfs(dfs, 0, 0, 0, 0);
    }
};