class Solution{
public:
    bool canIWin(int maxChoosableInteger,int desiredTotal){
        if(desiredTotal<=0)return true;

        int sum=maxChoosableInteger*(maxChoosableInteger+1)/2;
        if(sum<desiredTotal)return false;

        static int dp[1<<21][2];
        memset(dp,-1,sizeof(dp));

        auto dfs=[&](auto& self,int mask,int total,int turn)->int{
            if(total>=desiredTotal){
                if(turn)return 1;
                return 0;
            }

            if(dp[mask][turn]!=-1)return dp[mask][turn];

            int ans=turn?0:1;

            for(int i=1;i<=maxChoosableInteger;i++){
                if(mask&(1<<i))continue;

                int nxt=self(self,mask|(1<<i),total+i,turn^1);

                if(turn==0){
                    if(nxt==1){
                        ans=1;
                        break;
                    }
                    ans=0;
                }
                else{
                    if(nxt==0){
                        ans=0;
                        break;
                    }
                    ans=1;
                }
            }

            return dp[mask][turn]=ans;
        };

        return dfs(dfs,0,0,0);
    }
};