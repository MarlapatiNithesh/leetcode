class Dsu{
    int n;
    int[] par;
    int[] rank;
    int[] xr;

    Dsu(int n){
        this.n=n;
        this.par=new int[n];
        this.xr=new int[n];
        this.rank=new int[n];

        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }

    public int[] find(int u){
        if(u==par[u]){
            return new int[]{u,0};
        }

        int p=par[u];
        int[] val=find(p);

        par[u]=val[0];
        xr[u]^=val[1];

        return new int[]{par[u],xr[u]};
    }

    public boolean union(int u,int v,int w){
        int[] pa=find(u);
        int[] pb=find(v);

        if(pa[0]==pb[0]){
            if((pa[1]^pb[1])==w){
                return true;
            }
            return false;
        }

        if(rank[pa[0]]<rank[pb[0]]){
            int temp=pa[0];
            pa[0]=pb[0];
            pb[0]=temp;

            temp=pa[1];
            pa[1]=pb[1];
            pb[1]=temp;
        }

        par[pb[0]]=pa[0];

        xr[pb[0]]=pa[1]^pb[1]^w;

        if(rank[pa[0]]==rank[pb[0]]){
            rank[pa[0]]++;
        }

        return true;
    }
}

class Solution{
    public int numberOfEdgesAdded(int n,int[][] edges){
        Dsu ds=new Dsu(n);
        int cnt=0;

        for(int[] ed:edges){
            if(ds.union(ed[0],ed[1],ed[2])){
                cnt++;
            }
        }

        return cnt;
    }
}