class Dsu{
    int n;
    int[] par;
    int[] rank;

    Dsu(int n){
        this.n=n;
        this.par=new int[n];
        this.rank=new int[n];

        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }

    public int find(int u){
        if(u==par[u]){
            return u;
        }
        return par[u]=find(par[u]);
    }

    public boolean union(int u,int v){
        int pa=find(u);
        int pb=find(v);

        if(pa==pb){
            return false;
        }

        if(rank[pa]<rank[pb]){
            int temp=pa;
            pa=pb;
            pb=temp;
        }

        par[pb]=pa;

        if(rank[pa]==rank[pb]){
            rank[pa]++;
        }

        return true;
    }
}

class Solution {
    private boolean check(int n,int[][] edges,int k,int x){
        Dsu ds=new Dsu(n);

        for(int[] ed:edges){
            if(ed[3]==1){
                if(ed[2]<x){
                    return false;
                }

                if(!ds.union(ed[0],ed[1])){
                    return false;
                }
            }
        }

        for(int[] ed:edges){
            if(ed[3]==0 && ed[2]>=x){
                ds.union(ed[0],ed[1]);
            }
        }

        for(int[] ed:edges){
            if(k>0 && ed[3]==0 && 2*ed[2]>=x){
                if(ds.union(ed[0],ed[1])){
                    k--;
                }
            }
        }

        for(int i=0;i<n;i++){
            ds.find(i);
        }

        int root=ds.par[0];

        for(int i=0;i<n;i++){
            if(root!=ds.par[i]){
                return false;
            }
        }

        return true;
    }

    public int maxStability(int n,int[][] edges,int k){
        int lo=0,hi=200005;
        int ans=-1;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(check(n,edges,k,mid)){
                ans=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }

        return ans;
    }
}