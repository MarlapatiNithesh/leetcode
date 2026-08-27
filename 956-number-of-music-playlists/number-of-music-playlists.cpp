class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numMusicPlaylists(int n, int goal, int k) {

        int dp[101][101];
        memset(dp, -1, sizeof(dp));

        auto dfs = [&](auto&& self, int g, int used) -> int {

            if (g == 0) {
                return used == n;
            }

            if (dp[g][used] != -1)
                return dp[g][used];

            long long ans = 0;

            for (int i = used + 1; i <= n; i++) {

                ans += self(self, g - 1, used + 1);
                ans %= MOD;
            }

            if (used > k) {

                for (int i = 1; i <= used - k; i++) {

                    ans += self(self, g - 1, used);
                    ans %= MOD;
                }
            }

            return dp[g][used] = ans;
        };

        return dfs(dfs, goal, 0);
    }
};