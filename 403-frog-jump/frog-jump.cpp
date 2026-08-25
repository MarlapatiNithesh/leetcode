class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[n - 1][i] = 1;
        }

        for (int idx = n - 2; idx >= 0; idx--) {

            for (int i = n; i >= 0; i--) {

                for (int j = i - 1; j <= i + 1; j++) {

                    if (j <= 0 || j > n) continue;

                    int pos = stones[idx] + j;

                    auto it = mp.find(pos);

                    if (it == mp.end()) continue;

                    int nextidx = it->second;

                    if (dp[nextidx][j]) {
                        dp[idx][i] = 1;
                        break;
                    }
                }
            }
        }

        return dp[0][0];
    }
};