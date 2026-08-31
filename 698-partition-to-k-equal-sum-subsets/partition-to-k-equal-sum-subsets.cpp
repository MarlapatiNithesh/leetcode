class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();

        for(int i=0;i<n;i++)sum+=nums[i];

        if(sum%k)return false;

        sum/=k;

        vector<int>dp(1<<n,-1);

        auto dfs=[&](auto& slef,int mask,int s,int k)->int{
            if(k==0){
                return 1;
            }

            if(dp[mask]!=-1)return dp[mask];

            int ans=0;

            for(int i=0;i<n;i++){
                if(mask&(1<<i))continue;
                if(s-nums[i]<0)continue;

                if(s-nums[i]==0){
                    ans=slef(slef,mask|(1<<i),sum,k-1);
                }
                else{
                    ans=slef(slef,mask|(1<<i),s-nums[i],k);
                }

                if(ans)return dp[mask]=1;
            }

            return dp[mask]=0;
        };

        return dfs(dfs,0,sum,k);
    }
};