class Solution {
public:
    int rob(vector<int>& nums) {
       int n=nums.size();
       if(n==1)return nums[0];
       vector<int>dp1(n+1,-1),dp2(n+1,-1);
       auto dfs=[&](auto& slef,int i,int en,vector<int>&dp)->int{
          if(i>en)return 0;
          if(dp[i]!=-1)return dp[i];
          dp[i]=max(nums[i]+slef(slef,i+2,en,dp),slef(slef,i+1,en,dp));
          return dp[i];
       };
       return max(dfs(dfs,0,n-2,dp1),dfs(dfs,1,n-1,dp2));
    }
};