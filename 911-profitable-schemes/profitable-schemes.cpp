class Solution {  
public:  
    static const int MOD = 1e9 + 7;  

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {  
        int m = group.size();  

        int M = n + 1;
        int P = minProfit + 1;

        vector<int> dp(M * P, 0);

        auto get = [&](int mem, int pr) -> int& {
            return dp[mem * P + pr];
        };

        get(0, 0) = 1;

        for(int i = 0; i < m; i++) {
            for(int mem = n; mem >= group[i]; mem--) {
                for(int pr = minProfit; pr >= 0; pr--) {

                    int npr = min(minProfit, pr + profit[i]);

                    get(mem, npr) = 
                        (get(mem, npr) + get(mem - group[i], pr)) % MOD;
                }
            }
        }

        int ans = 0;

        for(int mem = 0; mem <= n; mem++) {
            ans = (ans + get(mem, minProfit)) % MOD;
        }

        return ans;
    }  
};