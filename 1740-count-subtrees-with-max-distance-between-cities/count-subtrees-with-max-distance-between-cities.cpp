class Solution { 
public: 
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) { 
        vector<int>adj[n]; 
        for(auto it:edges){ 
            it[0]--,it[1]--; 
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        } 
        vector<int>pa(n,-1),depth(n,0); 
        auto dfs=[&](auto& slef,int node,int p)->void{ 
            pa[node]=p; 
            for(auto it:adj[node]){ 
                if(it==p)continue; 
                depth[it]=depth[node]+1; 
                slef(slef,it,node); 
            } 
        }; 
        dfs(dfs,0,-1); 
        auto dist=[&](int u,int v){ 
            int ans=0; 
            while(depth[u]>depth[v]){ 
                ans++; 
                u=pa[u]; 
            } 
            while(depth[v]>depth[u]){ 
                ans++; 
                v=pa[v]; 
            } 
            while(u!=v){ 
                ans+=2; 
                u=pa[u]; 
                v=pa[v]; 
            } 
            return ans; 
        }; 
        vector<vector<int>>dp(n,vector<int>(n,0)); 
        for(int u=0;u<n;u++){ 
            for(int v=0;v<n;v++){ 
                dp[u][v]=dist(u,v); 
            } 
        } 
        vector<int>ans(n-1,0); 
        for(int mask=1;mask<(1<<n);mask++){ 
            int cnt=__builtin_popcount(mask); 
            if(cnt<=1)continue; 
            queue<int>q; 
            int st; 
            for(int i=0;i<n;i++){ 
                if((1<<i)&mask){ 
                    q.push(i); 
                    st=i; 
                    break; 
                } 
            } 
            vector<int>vis(n,0); 
            vis[st]=1; 
            int got=0; 
            while(!q.empty()){ 
                auto it=q.front();q.pop(); 
                got++; 
                for(auto ch:adj[it]){ 
                    if(!(mask&(1<<ch)))continue; 
                    if(vis[ch])continue; 
                    vis[ch]=1; 
                    q.push(ch); 
                } 
            } 
            if(got!=cnt)continue; 
            int mx=0; 
            for(int u=0;u<n;u++){ 
                if(!((1<<u)&mask))continue; 
                for(int v=0;v<n;v++){ 
                    if(!((1<<v)&mask))continue; 
                    mx=max(mx,dp[u][v]); 
                } 
            } 
            ans[mx-1]++; 
        } 
        return ans; 
    } 
};