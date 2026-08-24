class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[query_row+1][query_glass+1];
        fill(&dp[0][0],&dp[0][0]+(query_row+1)*(query_glass+1),-1.0);
        auto dfs = [&](auto& self, int i, int j) -> double {
            if(i == 0 && j == 0) {
                return poured;
            }
            if(j < 0 || j > i) return 0.0;
            if(dp[i][j]!=-1)return dp[i][j];
            double left = self(self, i - 1, j - 1);
            double right = self(self, i - 1, j);
            double fromLeft = max(0.0, (left - 1.0) / 2.0);
            double fromRight = max(0.0, (right - 1.0) / 2.0);

            return dp[i][j]=fromLeft + fromRight;
        };

        return min(1.0, dfs(dfs, query_row, query_glass));
    }
};