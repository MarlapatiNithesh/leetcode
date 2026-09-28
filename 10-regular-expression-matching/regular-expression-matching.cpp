class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        int dp[n + 1][m + 1];
        memset(dp, -1, sizeof(dp));

        auto dfs = [&](auto &self, int idx1, int idx2) -> bool {
            if (idx2 == m) return idx1 == n;

            if (dp[idx1][idx2] != -1) return dp[idx1][idx2];

            bool isMatch = (idx1 < n && (p[idx2] == '.' || s[idx1] == p[idx2]));

            if (idx2 + 1 < m && p[idx2 + 1] == '*') {
                bool notTake = self(self, idx1, idx2 + 2);
                bool take = isMatch && self(self, idx1 + 1, idx2);
                return dp[idx1][idx2] = take || notTake;
            }

            return dp[idx1][idx2] = isMatch && self(self, idx1 + 1, idx2 + 1);
        };

        return dfs(dfs, 0, 0);
    }
};