class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs,int k) {
        int n=jobs.size();
        int dp[13][1<<12];
        memset(dp,-1,sizeof(dp));

        int done=(1<<n)-1;

        auto dfs=[&](auto& self,int k,int mask)->int{
            if(mask==done){
                return 0;
            }

            if(k==0){
                return INT_MAX;
            }

            if(dp[k][mask]!=-1){
                return dp[k][mask];
            }

            int ans=INT_MAX;

            for(int sub=mask;;sub=(sub+1)|mask){
                int curr=0;

                for(int i=0;i<n;i++){
                    if((sub&(1<<i))&&!(mask&(1<<i))){
                        curr+=jobs[i];
                    }
                }

                int temp=self(self,k-1,sub);

                if(temp!=INT_MAX){
                    ans=min(ans,max(curr,temp));
                }

                if(sub==done){
                    break;
                }
            }

            return dp[k][mask]=ans;
        };

        return dfs(dfs,k,0);
    }
};
