class Solution {
    public int longestValidParentheses(String s) {
        if(s.equals(""))return 0;
        List<Integer>st=new ArrayList<>();
        st.add(-1);
        int idx=0,ans=0;
        for(char ch:s.toCharArray()){
            if(ch=='('){
                st.add(idx);
            }else{
                if(!st.isEmpty()){
                    st.remove(st.size()-1);
                }
                if(st.isEmpty()){
                    st.add(idx);
                }else{
                    ans=Math.max(ans,idx-st.get(st.size()-1));
                }
            }
            idx++;
        }
        return ans;
    }
}