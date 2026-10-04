class Dsu{
    int n;
    int[] par;
    int[] rank;
    int[] sum;

    Dsu(int n){
        this.n=n;
        this.par=new int[n];
        this.rank=new int[n];
        this.sum=new int[n];

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
        sum[u]+=val[1];

        return new int[]{par[u],sum[u]};
    }

    public boolean union(int u,int v,int w){
        int[] pa=find(u);
        int[] pb=find(v);

        if(pa[0]==pb[0]){
            return (pa[1]+w-pb[1])%2==0;
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

        sum[pb[0]]=w+pa[1]-pb[1];

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