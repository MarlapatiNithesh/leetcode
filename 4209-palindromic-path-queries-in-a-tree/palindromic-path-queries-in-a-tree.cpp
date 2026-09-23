class SegTree{
public:
   vector<int>sg;
   vector<int>val;
   int n;
   SegTree(vector<int>&a){
    this->val=a;
    this->n=a.size();
    sg.resize(4*n,0);
    build(0,n-1,0);
   }
   void build(int l,int r,int idx){
    if(l==r){
        sg[idx]=val[l];
        return;
    }
    int mid=l+(r-l)/2;
    build(l,mid,2*idx+1);
    build(mid+1,r,2*idx+2);
    sg[idx]=sg[2*idx+1]^sg[2*idx+2];
   }
   void update(int l,int r,int idx,int pos,int x){
    if(l==r){
        sg[idx]=x;
        return;
    }
    int mid=l+(r-l)/2;
    if(pos<=mid)update(l,mid,2*idx+1,pos,x);
    else update(mid+1,r,2*idx+2,pos,x);
    sg[idx]=sg[2*idx+1]^sg[2*idx+2];
   }
   int query(int l,int r,int idx,int ql,int qr){
    if(qr<l || r<ql)return 0;
    if(ql<=l && r<=qr)return sg[idx];
    int mid=l+(r-l)/2;
    return query(l,mid,2*idx+1,ql,qr)^query(mid+1,r,2*idx+2,ql,qr);
   }
   void update(int pos,int x){
    update(0,n-1,0,pos,x);
   }
   int query(int l,int r){
    return query(0,n-1,0,l,r);
   }
};

class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<int>adj[n];

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>in(n),ot(n),depth(n,0);
        vector<int>val(2*n);
        int timer=0;

        int up[n][30];

        auto dfs=[&](auto& slef,int node,int pa)->void{
            up[node][0]=pa;

            in[node]=timer;
            val[timer++]=1<<(s[node]-'a');

            for(auto it:adj[node]){
                if(it==pa)continue;

                depth[it]=depth[node]+1;
                slef(slef,it,node);
            }

            ot[node]=timer;
            val[timer++]=1<<(s[node]-'a');
        };

        dfs(dfs,0,-1);

        for(int i=1;i<30;i++){
            for(int j=0;j<n;j++){
                if(up[j][i-1]!=-1)
                    up[j][i]=up[up[j][i-1]][i-1];
                else
                    up[j][i]=-1;
            }
        }

        auto kthAnc=[&](int u,int k)->int{
            for(int i=0;i<30;i++){
                if((1<<i)&k){
                    u=up[u][i];
                    if(u==-1)return -1;
                }
            }
            return u;
        };

        auto lca=[&](int u,int v)->int{
            if(depth[u]<depth[v])swap(u,v);

            u=kthAnc(u,depth[u]-depth[v]);

            if(u==v)return u;

            for(int i=29;i>=0;i--){
                if(up[u][i]!=-1 && up[v][i]!=-1 && up[u][i]!=up[v][i]){
                    u=up[u][i];
                    v=up[v][i];
                }
            }

            return up[u][0];
        };

        SegTree st(val);

        auto rootPath=[&](int u)->int{
            return st.query(0,in[u]);
        };

        vector<bool>ans;

        for(auto it:queries){
            stringstream ss(it);

            string type;
            int u,v;
            char c;

            ss>>type;

            if(type=="update"){
                ss>>u>>c;

                int x=(1<<(s[u]-'a'))^(1<<(c-'a'));

                st.update(in[u],val[in[u]]^x);
                st.update(ot[u],val[ot[u]]^x);

                val[in[u]]^=x;
                val[ot[u]]^=x;

                s[u]=c;
            }else{
                ss>>u>>v;

                int p=lca(u,v);

                int x=rootPath(u)^rootPath(v)^(1<<(s[p]-'a'));

                if((x&(x-1))==0)
                    ans.push_back(true);
                else
                    ans.push_back(false);
            }
        }

        return ans;
    }
};