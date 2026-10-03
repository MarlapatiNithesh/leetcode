class Solution {
    public int[] par;

    public int[] findRedundantDirectedConnection(int[][] edges) {
        int n=edges.length;

        par=new int[n];
        Arrays.fill(par,-1);

        int[] ed1=null,ed2=null;

        for(int[] ed:edges){
            int u=ed[0]-1;
            int v=ed[1]-1;

            if(par[v]!=-1){
                ed1=new int[]{par[v],v};
                ed2=new int[]{u,v};
            }else{
                par[v]=u;
            }
        }

        for(int i=0;i<n;i++){
            par[i]=i;
        }

        for(int[] ed:edges){
            int u=ed[0]-1;
            int v=ed[1]-1;
            if(ed2!=null && u==ed2[0] && v==ed2[1]){
                continue;
            }
            int pu=find(u);
            int pv=find(v);
            if(pu==pv){
                if(ed1!=null){
                    return new int[]{ed1[0]+1,ed1[1]+1};
                }
                return new int[]{u+1,v+1};
            }
            par[pv]=pu;
        }

        if(ed2!=null){
            return new int[]{ed2[0]+1,ed2[1]+1};
        }
        return new int[0];
    }

    public int find(int u){
        if(u==par[u]){
            return u;
        }

        return par[u]=find(par[u]);
    }
}