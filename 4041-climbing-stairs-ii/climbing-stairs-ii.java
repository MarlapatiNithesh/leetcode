
import java.util.*;

class Solution {
    int n;
    int[] costs;
    int[][] dp;

    private int dfs(int i, int j) {
        if (i == n) {
            return 0;
        }
        if (i>n) {
            return Integer.MAX_VALUE;
        }
        if (dp[i][j + 1] != -1) {
            return dp[i][j + 1];
        }
        int ans = Integer.MAX_VALUE;
        for (int k = 1; k <= 3; k++) {
            if (i + k <= n) {
                int temp = dfs(i + k, k);
                if (temp != Integer.MAX_VALUE) {
                    ans = Math.min(ans, costs[i + k - 1] + k * k + temp);
                }
            }
        }
        return dp[i][j + 1] = ans;
    }

    public int climbStairs(int n, int[] costs) {
        this.n = n;
        this.costs = costs;
        dp = new int[n + 1][5];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], -1);
        }
        return dfs(0, -1);
    }
}
