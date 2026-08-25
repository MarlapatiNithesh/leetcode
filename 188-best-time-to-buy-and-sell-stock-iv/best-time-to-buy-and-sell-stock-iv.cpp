class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        int dp[1001][101][2];
        fill(&dp[0][0][0],
             &dp[0][0][0] + 1001 * 101 * 2,
             0);

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int j = 1; j <= k; j++) {
                for (int h = 0; h < 2; h++) {

                    int tt, nt;

                    nt = dp[idx + 1][j][h];

                    if (h == 0) {
                        tt = -prices[idx] + dp[idx + 1][j][1];
                    }
                    else {
                        tt = prices[idx] + dp[idx + 1][j - 1][0];
                    }

                    dp[idx][j][h] = max(tt, nt);
                }
            }
        }

        return dp[0][k][0];
    }
};