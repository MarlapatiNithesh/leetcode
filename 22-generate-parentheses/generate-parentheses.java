class Solution {
    public List<String> ans;

    public boolean check(String s) {
        Deque<Character> st = new ArrayDeque<>();

        for(char ch : s.toCharArray()) {
            if(!st.isEmpty() && st.peek() == '(' && ch == ')') {
                st.pop();
            } else {
                st.push(ch);
            }
        }

        return st.isEmpty();
    }

    public void dfs(int n, StringBuilder s, int idx) {
        if(s.length() == 2 * n) {
            if(check(s.toString())) {
                ans.add(s.toString());
            }
            return;
        }

        for(int i = idx; i < 2 * n; i++) {
            s.append('(');
            dfs(n, s, i + 1);
            s.deleteCharAt(s.length() - 1);

            s.append(')');
            dfs(n, s, i + 1);
            s.deleteCharAt(s.length() - 1);
        }
    }

    public List<String> generateParenthesis(int n) {
        ans = new ArrayList<>();
        dfs(n, new StringBuilder(), 0);
        return ans;
    }
}