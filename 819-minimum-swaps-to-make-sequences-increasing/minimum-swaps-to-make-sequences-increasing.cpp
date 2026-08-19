class Solution {
public:

    struct CustomHash {
        size_t operator()(const tuple<int, int, int>& t) const {
            auto [a, b, c] = t;

            size_t h1 = hash<int>{}(a);
            size_t h2 = hash<int>{}(b);
            size_t h3 = hash<int>{}(c);

            return h1 ^ (h2 << 1) ^ (h3 << 2);
        }
    };

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        unordered_map<tuple<int, int, int>, int, CustomHash> dp;

        auto dfs = [&](auto& self, int idx, int prev1, int prev2) -> int {

            if (idx >= n)
                return 0;

            auto key = make_tuple(idx, prev1, prev2);

            if (dp.count(key))
                return dp[key];

            int notSwap = INT_MAX;
            int take = INT_MAX;

            // Don't swap
            if (idx == 0) {
                notSwap = self(
                    self,
                    idx + 1,
                    nums1[idx],
                    nums2[idx]
                );
            }
            else if (prev1 < nums1[idx] &&
                     prev2 < nums2[idx]) {

                notSwap = self(
                    self,
                    idx + 1,
                    nums1[idx],
                    nums2[idx]
                );
            }

            // Swap
            if (idx == 0) {
                take = 1 + self(
                    self,
                    idx + 1,
                    nums2[idx],
                    nums1[idx]
                );
            }
            else if (prev1 < nums2[idx] &&
                     prev2 < nums1[idx]) {

                int x = self(
                    self,
                    idx + 1,
                    nums2[idx],
                    nums1[idx]
                );

                if (x != INT_MAX)
                    take = 1 + x;
            }

            return dp[key] = min(take, notSwap);
        };

        return dfs(dfs, 0, -1, -1);
    }
};