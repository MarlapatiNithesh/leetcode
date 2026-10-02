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

    public void dfs(int n, String s) {
        if(s.length() == 2 * n) {
            if(check(s)) {
                ans.add(s);
            }
            return;
        }

        dfs(n, s + "(");
        dfs(n, s + ")");
    }

    public List<String> generateParenthesis(int n) {
        ans = new ArrayList<>();
        dfs(n, "");
        return ans;
    }
}