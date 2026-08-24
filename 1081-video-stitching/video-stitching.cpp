class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();
        sort(clips.begin(), clips.end());
        int dp[101][102];
        fill(&dp[0][0],&dp[0][0]+101*101,-1);
        auto dfs = [&](auto& self, int idx, int en) -> int {
            if (en >= time) return 0;
            if (idx >= n) return INT_MAX;
            if(dp[idx][en+1]!=-1)return dp[idx][en+1];
            int nt = self(self, idx + 1, en);
            int tt = INT_MAX;
            if (clips[idx][0] == 0 && en == -1) {
                int temp = self(self, idx + 1, clips[idx][1]);
                if (temp != INT_MAX)
                    tt = 1 + temp;
            }
            else if (clips[idx][0] <= en && clips[idx][1] > en) {
                int temp = self(self, idx + 1, clips[idx][1]);
                if (temp != INT_MAX)
                    tt = 1 + temp;
            }
            return dp[idx][en+1]=min(tt, nt);
        };

        int ans = dfs(dfs, 0, -1);

        return ans == INT_MAX ? -1 : ans;
    }
};