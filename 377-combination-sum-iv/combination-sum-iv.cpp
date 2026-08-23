class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(1001,-1);
        auto dfs=[&](auto& slef,int tt)->int{
            if(tt==0)return 1;
            if(dp[tt]!=-1)return dp[tt];
            int ans=0;
            for(int i=0;i<n;i++){
                if(tt-nums[i]>=0){
                    ans+=slef(slef,tt-nums[i]);
                }
            }
            return dp[tt]=ans;
        };
        return dfs(dfs,target);
        
    }
};