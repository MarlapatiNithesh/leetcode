class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();

        map<int,int> mp;

        auto dfs = [&](auto& self, int idx, int cnt) -> int {
            if(idx >= m) {
                for(auto it : mp) {
                    if(it.second != 0) {
                        return INT_MIN;
                    }
                }
                return cnt;
            }

            int nt = self(self, idx + 1, cnt);

            mp[requests[idx][0]]--;
            mp[requests[idx][1]]++;

            int temp = self(self, idx + 1, cnt + 1);

            mp[requests[idx][0]]++;
            mp[requests[idx][1]]--;

            return max(nt, temp);
        };

        return dfs(dfs, 0, 0);
    }
};