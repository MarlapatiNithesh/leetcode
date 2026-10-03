class Solution {
    public int[] findRedundantDirectedConnection(int[][] edges) {
        int n=edges.length;

        int[] par=new int[n];
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

        if(ed2!=null){
            if(check(edges,ed2,n)){
                return new int[]{ed2[0]+1,ed2[1]+1};
            }

            return new int[]{ed1[0]+1,ed1[1]+1};
        }

        for(int i=n-1;i>=0;i--){
            if(check(edges,new int[]{edges[i][0]-1,edges[i][1]-1},n)){
                return edges[i];
            }
        }

        return new int[0];
    }

    boolean check(int[][] edges,int[] rem,int n){
        List<List<Integer>> adj=new ArrayList<>();

        for(int i=0;i<n;i++){
            adj.add(new ArrayList<>());
        }

        int[] in=new int[n];

        for(int[] ed:edges){
            int u=ed[0]-1;
            int v=ed[1]-1;

            if(u==rem[0] && v==rem[1])continue;

            adj.get(u).add(v);
            in[v]++;
        }

        int root=-1;

        for(int i=0;i<n;i++){
            if(in[i]==0){
                root=i;
                break;
            }
        }

        if(root==-1)return false;

        Deque<Integer> q=new ArrayDeque<>();
        boolean[] vis=new boolean[n];

        q.offer(root);
        vis[root]=true;

        int cnt=0;

        while(!q.isEmpty()){
            int node=q.poll();
            cnt++;

            for(int ch:adj.get(node)){
                if(vis[ch])return false;

                vis[ch]=true;
                q.offer(ch);
            }
        }

        return cnt==n;
    }
}