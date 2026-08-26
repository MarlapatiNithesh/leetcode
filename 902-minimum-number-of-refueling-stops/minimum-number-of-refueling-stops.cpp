class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();

        long long dp[501][501];
        memset(dp, -1, sizeof(dp));

        auto dfs = [&](auto& self, int idx, int cnt) -> long long {

            if (dp[idx + 1][cnt] != -1)
                return dp[idx + 1][cnt];

            long long reach;

            if (idx == -1) {
                reach = startFuel;
            } else {
                reach = stations[idx][0] + stations[idx][1];
            }

            // try all previous possibilities
            long long ans = reach;

            for (int i = idx + 1; i < n; i++) {

                // station i cannot be reached from current reach
                if (stations[i][0] > ans)
                    break;

                ans = max(ans,
                    self(self, i, cnt + 1)
                );
            }

            return dp[idx + 1][cnt] = ans;
        };

        // Actually simpler and correct recursive DP:
        vector<vector<long long>> memo(n + 1,
                                      vector<long long>(n + 1, -1));

        auto solve = [&](auto& self, int idx, int stops) -> long long {

            if (memo[idx + 1][stops] != -1)
                return memo[idx + 1][stops];

            long long fuel;

            if (idx == -1)
                fuel = startFuel;
            else
                fuel = stations[idx][0] + stations[idx][1];

            return memo[idx + 1][stops] = fuel;
        };

        // DP: dp[k] = farthest reachable with k stops
        vector<long long> reach(n + 1, -1);
        reach[0] = startFuel;

        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {

                if (reach[j] >= stations[i][0]) {
                    reach[j + 1] = max(
                        reach[j + 1],
                        reach[j] + stations[i][1]
                    );
                }
            }
        }

        for (int i = 0; i <= n; i++) {
            if (reach[i] >= target)
                return i;
        }

        return -1;
    }
};