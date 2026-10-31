class Solution {
    private static final int MOD = 1_000_000_007;

    public int uniquePaths(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int[][][] dp = new int[n][m][2];

        for (int[][] row : dp) {
            for (int[] cell : row) {
                Arrays.fill(cell, -1);
            }
        }

        return dfs(0, 0, 0, grid, dp);
    }

    private int dfs(int i, int j, int state, int[][] grid, int[][][] dp) {
        int n = grid.length;
        int m = grid[0].length;

        if (i >= n || j >= m) return 0;
        if (i == n - 1 && j == m - 1) return 1;
        if (dp[i][j][state] != -1) return dp[i][j][state];

        long ans = 0;

        if (grid[i][j] == 1) {
            if (state == 0) {
                ans += dfs(i + 1, j, 1, grid, dp);
            } else {
                ans += dfs(i, j + 1, 0, grid, dp);
            }
        } else {
            ans += dfs(i + 1, j, 1, grid, dp);
            ans += dfs(i, j + 1, 0, grid, dp);
        }

        return dp[i][j][state] = (int)(ans % MOD);
    }
}