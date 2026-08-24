class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> pref(n + 1);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }
        double dp[101][101][101];
        fill(&dp[0][0][0],&dp[0][0][0]+101*101*101,-1);

        auto dfs = [&](auto& self, int idx, int el, int cnt) -> double {
            if (idx == n) {
                if (el > 0 && cnt + 1 == k) {
                    int sum = pref[n] - pref[n - el];
                    return (double)sum / el;
                }
                return -1e18;
            }
            if(dp[idx][el][cnt]!=-1)return dp[idx][el][cnt];
            double take = self(
                self,
                idx + 1,
                el + 1,
                cnt
            );
            double nxt = -1e18;
            if (el > 0 && cnt + 1 < k) {
                int sum = pref[idx] - pref[idx - el];
                nxt = (double)sum / el +
                      self(
                          self,
                          idx,
                          0,
                          cnt + 1
                      );
            }
            return dp[idx][el][cnt]=max(take, nxt);
        };

        return dfs(dfs, 0, 0, 0);
    }
};