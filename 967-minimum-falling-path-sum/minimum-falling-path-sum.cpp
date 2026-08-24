class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int dp[101][101];
        fill(&dp[0][0],&dp[0][0]+101*101,-1e9);
        auto dfs = [&](auto& slef, int i, int j) -> int {
            if (j >= n || j < 0) return INT_MAX;
            if (i >= n) return 0;
            if(dp[i][j]!=-1e9)return dp[i][j];
            int take1 = INT_MAX, take2 = INT_MAX, take3 = INT_MAX, take4 = INT_MAX;
            take2 = matrix[i][j] + slef(slef, i + 1, j);
            int temp1 = slef(slef, i + 1, j - 1);
            if (temp1 != INT_MAX)
                take3 = matrix[i][j] + temp1;
            int temp2 = slef(slef, i + 1, j + 1);
            if (temp2 != INT_MAX)
                take4 = matrix[i][j] + temp2;
            if (i == 0 && j + 1 < n) {
                take1 = slef(slef, i, j + 1);
            }

            return dp[i][j]=min({take1, take2, take3, take4});
        };

        return dfs(dfs, 0, 0);
    }
};