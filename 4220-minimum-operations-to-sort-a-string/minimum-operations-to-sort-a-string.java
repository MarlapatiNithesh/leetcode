class Solution {
    public int minOperations(String s) {
        int n=s.length();
        char[] ch=s.toCharArray();
        Arrays.sort(ch);
        String sorted=new String(ch);
        if(sorted.equals(s)){
            return 0;
        }
        if(n<=2)return -1;
        if(sorted.charAt(0)==s.charAt(0)){
            return 1;
        }
        if(sorted.charAt(n-1)==s.charAt(n-1))return 1;
        int x=0,y=0;
        for(int i=1;i<n-1;i++){
            if(s.charAt(i)==sorted.charAt(0) || s.charAt(i)==sorted.charAt(n-1)){
                return 2;
            }
        }
        return 3;
    }
}