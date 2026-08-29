
class Solution{
public:
    static const int MOD=1e9+7;

    int ways(vector<string>& pizza,int k){
        int n=pizza.size(),m=pizza[0].size();

        int pre[n+1][m+1];
        memset(pre,0,sizeof(pre));

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                pre[i][j]=(pizza[i][j]=='A')+pre[i+1][j]+pre[i][j+1]-pre[i+1][j+1];
            }
        }

        int dp[n+1][m+1][k+1];
        memset(dp,-1,sizeof(dp));

        auto dfs=[&](auto& self,int idx1,int idx2,int cut)->int{

            if(cut+1==k){
                return pre[idx1][idx2]>0;
            }

            if(idx1>=n || idx2>=m || cut>=k)
                return 0;

            if(dp[idx1][idx2][cut]!=-1)
                return dp[idx1][idx2][cut];

            int ans=0;

            for(int i=0;i<max(n,m);i++){

                // horizontal cut
                if(i<n-1){
                    int upper=pre[idx1][idx2]-pre[i+1][idx2];

                    if(upper>0){
                        ans=(ans+self(self,i+1,idx2,cut+1))%MOD;
                    }
                }

                // vertical cut
                if(i<m-1){
                    int left=pre[idx1][idx2]-pre[idx1][i+1];

                    if(left>0){
                        ans=(ans+self(self,idx1,i+1,cut+1))%MOD;
                    }
                }
            }

            return dp[idx1][idx2][cut]=ans;
        };

        return dfs(dfs,0,0,0);
    }
};