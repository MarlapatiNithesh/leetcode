class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        int dp[101][101][2];
        fill(&dp[0][0][0],&dp[0][0][0]+101*101*2,-1);
        auto dfs=[&](auto& slef,int idx,int m,int turn)->int{
            if(idx>=n)return 0;
            if(dp[idx][m][turn]!=-1)return dp[idx][m][turn];
            int nt,tt;
            if(turn){
                nt=INT_MAX;
                for(int i=1;i<=2*m && idx+i<=n;i++){
                    nt=min(nt,slef(slef,idx+i,max(m,i),turn^1));
                }
                return nt;
            }else{
                tt=0;
                int sum=0;
                for(int i=1;i<=2*m && idx+i<=n;i++){
                    sum+=piles[idx+i-1];
                    tt=max(tt,sum+
                        slef(slef,idx+i,max(m,i),turn^1));
                }
                return dp[idx][m][turn]=tt;
            }
        };

        return dfs(dfs,0,1,0);
    }
};