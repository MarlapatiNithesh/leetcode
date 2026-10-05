class Solution {
    public int scoreOfParentheses(String s) {
        int n=s.length();
        int[] a=new int[n];
        int cnt=0;

        for(int i=0;i<n;i++){
            if(s.charAt(i)=='('){
                cnt++;
            }else{
                cnt--;
            }
            a[i]=cnt;
        }

        int ans=0;

        for(int i=0;i<n;i++){
            int prev=i>0?a[i-1]:0;
            int curr=a[i];
            int next=i+1<n?a[i+1]:0;

            if(s.charAt(i)==')' && prev>curr){
                if(i>0 && s.charAt(i-1)=='('){
                    ans+=1<<curr;
                }
            }
        }

        return ans;
    }
}