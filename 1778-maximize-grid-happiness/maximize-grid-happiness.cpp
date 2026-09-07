class Solution {
public:

    int m,n;
    int dp[5][5][3][32][32][7][7];
    int dfs(int row,int col,int previous,int prevusedmask,int previemask,int icount,int ecount)
    {
        if(col==m) return dfs(row+1,0,0,prevusedmask,previemask,icount,ecount);
        if(row==n) return 0;
        if(dp[row][col][previous][prevusedmask][previemask][icount][ecount]!=-1) return dp[row][col][previous][prevusedmask][previemask][icount][ecount];
        int ans1=INT_MIN,ans2=INT_MIN,ans3=INT_MIN;
        if(icount>0)
        {
            int upperval=0;
            int preval=0;
            if(previous==1) preval=-60;
            if(previous==2) preval=-10;
            int used=(prevusedmask>>col)&1;
            if(used&&(((previemask>>col)&1)==1)) upperval=-60;
            if(used&&(((previemask>>col)&1)==0)) upperval=-10;
            ans1=120+upperval+preval+dfs(row,1+col,1,prevusedmask|(1<<col),previemask|(1<<col),icount-1,ecount);
        }
        if(ecount>0)
        {
            int upperval=0;
            int preval=0;
            if(previous==1) preval=-10;
            if(previous==2) preval=40;
            int used=(prevusedmask>>col)&1;
            if(used&&((previemask>>col)&1)==1) upperval=-10;
            if(used&&((previemask>>col)&1)==0) upperval=40;
            ans2=40+upperval+preval+dfs(row,1+col,2,prevusedmask|(1<<col),previemask & ~(1<<col),icount,ecount-1);
        }
        ans3=dfs(row,1+col,0,prevusedmask & ~(1 << col),previemask,icount,ecount);
        return dp[row][col][previous][prevusedmask][previemask][icount][ecount]=max(max(ans1,ans2),ans3);
    }


    int getMaxGridHappiness(int mrow, int ncol, int iCount, int eCount) 
    {
        n=mrow;
        m=ncol;
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,0,0,0,iCount,eCount);
    }
};