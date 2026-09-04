class Solution {
public:
    int n;
    int m;
    int dp[12][1 << 13];
    int f(int i, int mask, vector<vector<int>>& cost) {
        if (i == n && (mask == (1 << m) - 1))
            return 0;
        
        if (i == n) {
            int ans = 0;
            for (int j = 0; j < m; j++) {
                if ((mask & (1 << j)) == 0) {
                    int mn = INT_MAX;

                    for (int k = 0; k < n; k++)
                        mn = min(mn, cost[k][j]);

                    ans += mn;
                }
            }
            return ans;
        }
        if(dp[i][mask]!=-1)return dp[i][mask];
        int cnt = INT_MAX;
        for (int j = 0; j < m; j++) {
            cnt = min(cnt, cost[i][j] + f(i + 1, mask | (1 << j), cost));
        }
        return dp[i][mask] = cnt;
    }
    int connectTwoGroups(vector<vector<int>>& cost) {
        n = cost.size();
        m = cost[0].size();
        memset(dp, -1, sizeof(dp));
        return f(0, 0, cost);
    }
};