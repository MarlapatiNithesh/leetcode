class Solution {
    Map<Integer, HashSet<String>> mp = new HashMap<>();
    Set<String>[] dp;
    int n;

    public List<String> removeInvalidParentheses(String s) {
        n = s.length();

        dp = new HashSet[n + 1];

        for (int i = 0; i <= n; i++) {
            dp[i] = new HashSet<>();
        }

        dfs(s, 0, "");

        int maxLen = 0;

        for (int len : mp.keySet()) {
            maxLen = Math.max(maxLen, len);
        }

        return new ArrayList<>(mp.get(maxLen));
    }

    void dfs(String s, int idx, String curr) {
        if (dp[idx].contains(curr)) {
            return;
        }

        dp[idx].add(curr);

        if (idx == n) {
            if (valid(curr)) {
                mp.putIfAbsent(curr.length(), new HashSet<>());
                mp.get(curr.length()).add(curr);
            }
            return;
        }

        // take
        dfs(s, idx + 1, curr + s.charAt(idx));

        // skip
        dfs(s, idx + 1, curr);
    }

    boolean valid(String s) {
        int bal = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c == '(') {
                bal++;
            } else if (c == ')') {
                bal--;

                if (bal < 0) {
                    return false;
                }
            }
        }

        return bal == 0;
    }
}