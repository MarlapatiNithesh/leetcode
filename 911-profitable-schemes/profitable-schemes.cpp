class Solution {  
public:  
    static const int MOD = 1e9 + 7;  

    struct custom_hash { 
        size_t operator()(const tuple<int,int,int>& t) const { 
            auto [a,b,c] = t; 
            size_t h1 = hash<int>{}(a); 
            size_t h2 = hash<int>{}(b); 
            size_t h3 = hash<int>{}(c); 
            return h1 ^ (h2 << 1) ^ (h3 << 2); 
        } 
    }; 

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {  
        int m = group.size(); 

        int dp[101][101][101];
        memset(dp, -1, sizeof(dp));

        auto dfs = [&](auto& self, int idx, int mem, int pr) -> int {  

            if(idx >= m) {  
                return pr >= minProfit;  
            } 

            if(dp[idx][mem][pr] != -1) 
                return dp[idx][mem][pr];

            int ans = 0;  

            if(mem + group[idx] <= n) {  
                int npr = min(minProfit, pr + profit[idx]); 

                ans = (ans + self(self, idx + 1, 
                                  mem + group[idx], npr)) % MOD;  
            }  

            ans = (ans + self(self, idx + 1, mem, pr)) % MOD;  

            return dp[idx][mem][pr] = ans;  
        };  

        return dfs(dfs, 0, 0, 0);  
    }  
};