class Solution {
public:
    vector<vector<vector<int>>> dp;

    int dfs(int idx1, int idx2, int turn, vector<int>& piles) {
        if (idx1 > idx2) return 0;

        if (dp[idx1][idx2][turn] != -1)
            return dp[idx1][idx2][turn];

        if (turn == 0) {
            return dp[idx1][idx2][turn] = max(
                piles[idx1] + dfs(idx1 + 1, idx2, 1, piles),
                piles[idx2] + dfs(idx1, idx2 - 1, 1, piles)
            );
        } else {
            return dp[idx1][idx2][turn] = min(
                -piles[idx1] + dfs(idx1 + 1, idx2, 0, piles),
                -piles[idx2] + dfs(idx1, idx2 - 1, 0, piles)
            );
        }
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        dp.assign(n, vector<vector<int>>(n, vector<int>(2, -1)));

        return dfs(0, n - 1, 0, piles) > 0;
    }
};