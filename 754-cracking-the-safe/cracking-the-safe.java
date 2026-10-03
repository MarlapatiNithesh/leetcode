class Pair {
    int node;
    int nxt;
    Pair(int node, int nxt) {
        this.node = node;
        this.nxt = nxt;
    }
}

class Solution {
    public String crackSafe(int n, int k) {
        if(n == 1) {
            String ans = "";
            for(int i = 0; i < k; i++) ans += i;
            return ans;
        }
        int cnt = 1;
        for(int i = 0; i < n - 1; i++) {
            cnt *= k;
        }
        List<Integer> next = new ArrayList<>();
        for(int i = 0; i < cnt; i++) {
            next.add(0);
        }
        List<Pair> st = new ArrayList<>();
        List<Integer> cir = new ArrayList<>();
        st.add(new Pair(0, -1));
        while(!st.isEmpty()) {
            int u = st.get(st.size() - 1).node;
            if(next.get(u) < k) {
                int d = next.get(u);
                next.set(u, d + 1);
                int v = (u * k + d) % cnt;
                st.add(new Pair(v, d));
            } else {
                Pair val = st.get(st.size() - 1);
                st.remove(st.size() - 1);
                if(val.nxt != -1) {
                    cir.add(val.nxt);
                }
            }
        }

        Collections.reverse(cir);
        String res = "";
        for(int i = 0; i < n - 1; i++) {
            res += '0';
        }
        for(int i = 0; i < cir.size(); i++) {
            res += cir.get(i);
        }
        return res;
    }
}