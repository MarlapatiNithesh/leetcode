class Solution {
    public Map<String,TreeMap<String,Integer>>adj;
    public List<String>ans;
    public void dfs(String node){
        TreeMap<String,Integer>st=adj.get(node);
        while(st!=null && !st.isEmpty()){
            String ch=st.firstKey();
            if(st.get(ch)==1){
                st.remove(ch);
            }else{
                st.put(ch,st.get(ch)-1);
            }
            dfs(ch);
        }
        ans.add(node);
    }
    public List<String> findItinerary(List<List<String>> tickets) {
        adj=new HashMap<>();
        ans=new ArrayList<>();
        for(List<String>ed:tickets){
            String fr=ed.get(0),to=ed.get(1);
            adj.computeIfAbsent(fr,x->new TreeMap<>()).merge(to,1,Integer::sum);
        }
        dfs("JFK");
        Collections.reverse(ans);
        return ans;
    }
}