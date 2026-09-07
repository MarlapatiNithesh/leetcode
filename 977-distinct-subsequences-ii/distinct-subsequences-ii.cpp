class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<long long> dp;

    long long dfs(string &s, int idx) {
        if (idx == s.size()) {
            long long ans = 0;

            for (int i = 0; i < 26; i++) {
                ans = (ans + dp[i]) % MOD;
            }

            return ans;
        }

        int c = s[idx] - 'a';

        // Number of subsequences before taking s[idx]
        long long sum = 1;  // take only s[idx]

        for (int i = 0; i < 26; i++) {
            sum = (sum + dp[i]) % MOD;
        }

        // Replace old subsequences ending with c
        dp[c] = sum;

        return dfs(s, idx + 1);
    }

    int distinctSubseqII(string s) {
        dp.assign(26, 0);

        return dfs(s, 0);
    }
};