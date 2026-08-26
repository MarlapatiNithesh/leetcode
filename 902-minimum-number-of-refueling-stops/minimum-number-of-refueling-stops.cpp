class Solution {
public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {

        int n = stations.size();

        // dp[i][j] = maximum distance reachable
        // after considering first i stations
        // using exactly j refuels
        long long dp[501][501];

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                dp[i][j] = -1;

        dp[0][0] = startFuel;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j <= i; j++) {

                if (dp[i][j] == -1)
                    continue;

                // NOT TAKE
                dp[i + 1][j] =
                    max(dp[i + 1][j], dp[i][j]);

                // TAKE
                if (dp[i][j] >= stations[i][0]) {

                    dp[i + 1][j + 1] =
                        max(dp[i + 1][j + 1],
                            dp[i][j] +
                            stations[i][1]);
                }
            }
        }

        for (int j = 0; j <= n; j++) {

            if (dp[n][j] >= target)
                return j;
        }

        return -1;
    }
};