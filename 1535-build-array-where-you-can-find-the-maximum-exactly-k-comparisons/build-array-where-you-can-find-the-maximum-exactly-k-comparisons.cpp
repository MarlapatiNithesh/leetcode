class Solution {
public:

    static const int MOD = 1e9 + 7;

    int numOfArrays(int n, int m, int k) {

        int dp[51][102][51];

        memset(dp, -1, sizeof(dp));

        auto dfs = [&](auto& slef, int n, int prev, int k1) -> int {

            if(n == 0)
                return k1 == 0;

            if(k1 < 0)
                return 0;

            if(dp[n][prev + 1][k1] != -1)
                return dp[n][prev + 1][k1];

            int ans = 0;

            for(int i = m; i >= 1; i--) {

                if(prev < i) {

                    ans = (ans +
                        slef(slef, n - 1, i, k1 - 1)
                    ) % MOD;

                } else {

                    ans = (ans +
                        slef(slef, n - 1, prev, k1)
                    ) % MOD;
                }
            }

            return dp[n][prev + 1][k1] = ans;
        };

        return dfs(dfs, n, -1, k);
    }
};