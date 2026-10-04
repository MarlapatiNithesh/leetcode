import java.util.*;
class Solution{
    int n;
    int[][] dp;
    String s;
    public boolean dfs(int idx,int bal){
        if(bal<0)return false;
        if(idx>=n)return bal==0;
        if(dp[idx][bal]!=-1)return dp[idx][bal]==1;
        boolean ans=false;
        if(s.charAt(idx)=='*'){
            if(dfs(idx+1,bal))ans=true;
            if(dfs(idx+1,bal+1))ans=true;
            if(dfs(idx+1,bal-1))ans=true;
        }
        if(s.charAt(idx)=='('){
            if(dfs(idx+1,bal+1))ans=true;
        }
        if(s.charAt(idx)==')'){
            if(dfs(idx+1,bal-1))ans=true;
        }
        dp[idx][bal]=ans?1:0;
        return ans;
    }
    public boolean checkValidString(String s){
        this.n=s.length();
        this.s=s;
        dp=new int[n][n+1];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return dfs(0,0);
    }
}