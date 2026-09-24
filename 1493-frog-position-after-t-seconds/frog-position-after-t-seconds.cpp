class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<int> adj[n];
        vector<int> par(n,-1), ch(n,0), dep(n,0);

        for(auto it: edges){
            it[0]--, it[1]--;
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        target--;

        auto dfs = [&](auto &self, int node, int pa)->void{
            par[node] = pa;
            int cnt = 0;
            for(auto it: adj[node]){
                if(it == pa) continue;
                dep[it] = dep[node] + 1;
                cnt++;
                self(self, it, node);
            }
            ch[node] = cnt;
        };

        dfs(dfs, 0, -1);

        if(dep[target] > t) return 0.0;
        if(dep[target] < t && ch[target] > 0) return 0.0;

        double ans = 1.0;
        while(par[target] != -1){
            ans *= 1.0 / ch[par[target]];
            target = par[target];
        }

        return ans;
    }
};