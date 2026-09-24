class Solution {
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        map<int,set<pair<int,int>>>mp;
        vector<int>ans(n,-1);

        auto gcd=[&](auto& self,int a,int b)->int{
            if(b==0)return a;
            return self(self,b,a%b);
        };

        auto dfs=[&](auto& self,int node,int pa,int timer)->void{
            int mx=-1,id=-1;

            for(auto &it:mp){
                if(gcd(gcd,it.first,nums[node])==1 && !it.second.empty()){
                    auto p=*it.second.rbegin();
                    if(p.first>mx){
                        mx=p.first;
                        id=p.second;
                    }
                }
            }

            ans[node]=id;
            mp[nums[node]].insert({timer,node});

            for(auto it:adj[node]){
                if(it==pa)continue;
                self(self,it,node,timer+1);
            }

            mp[nums[node]].erase({timer,node});
        };

        dfs(dfs,0,-1,0);
        return ans;
    }
};