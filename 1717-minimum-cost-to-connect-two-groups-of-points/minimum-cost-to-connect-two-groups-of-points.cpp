class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size();
        int m = cost[0].size();

        int M = 1 << m;

        // dp[mask] = minimum cost after processing some rows
        // and the connected columns are represented by mask
        vector<int> dp(M, INT_MAX);

        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            vector<int> ndp(M, INT_MAX);

            for (int mask = 0; mask < M; mask++) {

                if (dp[mask] == INT_MAX)
                    continue;

                for (int j = 0; j < m; j++) {

                    int nmask = mask | (1 << j);

                    ndp[nmask] = min(
                        ndp[nmask],
                        dp[mask] + cost[i][j]
                    );
                }
            }

            dp = ndp;
        }

        // Now all rows are connected.
        // Connect every column which is still unconnected.
        int ans = INT_MAX;

        for (int mask = 0; mask < M; mask++) {

            if (dp[mask] == INT_MAX)
                continue;

            int cur = dp[mask];

            for (int j = 0; j < m; j++) {

                if ((mask & (1 << j)) == 0) {

                    int mn = INT_MAX;

                    for (int k = 0; k < n; k++) {
                        mn = min(mn, cost[k][j]);
                    }

                    cur += mn;
                }
            }

            ans = min(ans, cur);
        }

        return ans;
    }
};