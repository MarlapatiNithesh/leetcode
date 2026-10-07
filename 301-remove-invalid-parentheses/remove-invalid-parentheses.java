class Solution {
    Map<Integer, HashSet<String>> mp = new HashMap<>();
    int n;

    public List<String> removeInvalidParentheses(String s) {
        n = s.length();

        StringBuilder sb = new StringBuilder();
        dfs(s, 0, 0, sb);

        int maxLen = 0;

        for (int len : mp.keySet()) {
            maxLen = Math.max(maxLen, len);
        }

        return new ArrayList<>(mp.get(maxLen));
    }

    void dfs(String s, int idx, int bal, StringBuilder sb) {
        if (bal < 0) {
            return;
        }

        if (idx == n) {
            if (bal == 0) {
                mp.putIfAbsent(sb.length(), new HashSet<>());
                mp.get(sb.length()).add(sb.toString());
            }
            return;
        }

        char c = s.charAt(idx);

        // take
        sb.append(c);

        if (c == '(') {
            dfs(s, idx + 1, bal + 1, sb);
        } else if (c == ')') {
            dfs(s, idx + 1, bal - 1, sb);
        } else {
            dfs(s, idx + 1, bal, sb);
        }

        sb.deleteCharAt(sb.length() - 1);

        // skip
        dfs(s, idx + 1, bal, sb);
    }
}