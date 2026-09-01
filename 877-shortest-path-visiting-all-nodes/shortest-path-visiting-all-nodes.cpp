class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int ans=INT_MAX;

        for(int i=0;i<n;i++){
            queue<pair<int,int>>q;
            vector<vector<bool>>vis(n,vector<bool>(1<<n,false));

            q.push({i,1<<i});
            vis[i][1<<i]=true;

            int dist=0;

            while(!q.empty()){
                int sz=q.size();

                while(sz--){
                    auto it=q.front();
                    q.pop();

                    if(it.second==(1<<n)-1)
                        ans=min(ans,dist);

                    for(auto nei:graph[it.first]){
                        int newmask=it.second|(1<<nei);

                        if(vis[nei][newmask])continue;

                        vis[nei][newmask]=true;
                        q.push({nei,newmask});
                    }
                }

                dist++;
            }
        }

        return ans;
    }
};