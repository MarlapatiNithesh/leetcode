class Solution {
public:
    int minSteps(int n) {
        const int INF = 1e9;
        // dp[c][s][la] -> flat array, avoids nested vector allocation overhead
        vector<int> dp((n + 1) * (n + 1) * 2, INF);
        auto idx = [&](int c, int s, int la) {
            return (c * (n + 1) + s) * 2 + la;
        };

        for (int c = 0; c <= n; c++) {
            dp[idx(c, n, 0)] = 0;
            dp[idx(c, n, 1)] = 0;
        }

        for (int s = n - 1; s >= 1; s--) {
            for (int la = 0; la < 2; la++) {
                int cp = INF, pa = INF;
                if (la) cp = 1 + dp[idx(s, s, 0)];
                if (2 * s <= n) pa = 1 + dp[idx(s, 2 * s, 1)];
                dp[idx(s, s, la)] = min(cp, pa);
            }
            for (int c = 0; c <= n; c++) {
                if (c == s) continue;
                for (int la = 0; la < 2; la++) {
                    int cp = INF, pa = INF;
                    if (la) cp = 1 + dp[idx(s, s, 0)];
                    if (c > 0 && s + c <= n) pa = 1 + dp[idx(c, s + c, 1)];
                    dp[idx(c, s, la)] = min(cp, pa);
                }
            }
        }

        return dp[idx(0, 1, 1)];
    }
};