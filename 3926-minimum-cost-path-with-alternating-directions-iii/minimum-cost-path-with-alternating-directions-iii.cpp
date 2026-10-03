class Solution {
public:
    long long minCost(int m,int n,vector<vector<int>>& penalty){
        using ll=long long;
        using T=tuple<ll,int,int,int>;
        const ll INF=1e18;
        vector<vector<vector<ll>>> dist(m,vector<vector<ll>>(n,vector<ll>(2,INF)));
        priority_queue<T,vector<T>,greater<T>> pq;
        dist[0][0][1]=1;
        pq.push({1,0,0,1});
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        while(!pq.empty()){
            auto [cost,x,y,p]=pq.top();
            pq.pop();
            if(cost+penalty[x][y]<dist[x][y][p^1]){
                dist[x][y][p^1]=cost+penalty[x][y];
                pq.push({cost+penalty[x][y],x,y,p^1});
            }
            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx<0||ny<0||nx>=m||ny>=n) continue;
                ll nwcost=cost+1LL*(nx+1)*(ny+1);
                bool v=0;
                if(p){
                    if((dx[k]==0&&dy[k]==1)||(dx[k]==1&&dy[k]==0)) v=1;
                }else{
                    if((dx[k]==0&&dy[k]==-1)||(dx[k]==-1&&dy[k]==0)) v=1;
                }
                if(!v) nwcost+=penalty[x][y];
                if(nwcost<dist[nx][ny][p^1]){
                    dist[nx][ny][p^1]=nwcost;
                    pq.push({nwcost,nx,ny,p^1});
                }
            }
        }
        return min(dist[m-1][n-1][0],dist[m-1][n-1][1]);
    }
};