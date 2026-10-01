class Solution {
    public boolean isValid(String s) {
        Deque<Character> st = new ArrayDeque<>();

        for (char ch : s.toCharArray()) {
            if (!st.isEmpty() && 
                ((st.peek() == '(' && ch == ')') ||
                 (st.peek() == '{' && ch == '}') ||
                 (st.peek() == '[' && ch == ']'))) {
                st.pop();
            } else {
                st.push(ch);
            }
        }

        return st.isEmpty();
    }
}