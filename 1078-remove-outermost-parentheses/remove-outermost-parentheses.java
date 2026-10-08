class Solution {
    public String removeOuterParentheses(String s) {
        int bal=0;
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='('){
                bal++;
                if(bal>1){
                    sb.append(s.charAt(i));
                }
            }else{
                bal--;
                if(bal!=0){
                    sb.append(s.charAt(i));
                }
            }
        }
        return sb.toString();
    }
}