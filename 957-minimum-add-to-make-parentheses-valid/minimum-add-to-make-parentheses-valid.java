class Solution {
    public int minAddToMakeValid(String s) {
        int o=0,c=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='('){
                o++;
            }else{
                c++;
            }
            if(c>o){
                o++;
                ans++;
            }
        }
        if(o>c){
            ans+=o-c;
        }
        return ans;
    }
}