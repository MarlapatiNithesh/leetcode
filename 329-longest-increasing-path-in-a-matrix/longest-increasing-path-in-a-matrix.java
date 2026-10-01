class Solution {
    int m,n;
    int[][] dp;

    int dfs(int i,int j,int[][] matrix){
        if(dp[i][j]!=0){
            return dp[i][j];
        }

        int ans=1;

        if(i>0 && matrix[i-1][j]>matrix[i][j]){
            ans=Math.max(ans,1+dfs(i-1,j,matrix));
        }

        if(i+1<m && matrix[i+1][j]>matrix[i][j]){
            ans=Math.max(ans,1+dfs(i+1,j,matrix));
        }

        if(j>0 && matrix[i][j-1]>matrix[i][j]){
            ans=Math.max(ans,1+dfs(i,j-1,matrix));
        }

        if(j+1<n && matrix[i][j+1]>matrix[i][j]){
            ans=Math.max(ans,1+dfs(i,j+1,matrix));
        }

        return dp[i][j]=ans;
    }

    public int longestIncreasingPath(int[][] matrix) {
        m=matrix.length;
        n=matrix[0].length;

        dp=new int[m][n];

        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=Math.max(ans,dfs(i,j,matrix));
            }
        }

        return ans;
    }
}