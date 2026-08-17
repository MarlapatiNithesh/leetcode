class Solution {
public:
    int findTargetSumWays(vector<int>& nums,int target) {
        auto dfs=[&](auto&self,int idx,int sum)->int{
            if(idx==nums.size()){
                return sum==target;
            }

            int ans=0;
            ans+=self(self,idx+1,sum+nums[idx]);
            ans+=self(self,idx+1,sum-nums[idx]);
            return ans;
        };

        return dfs(dfs,0,0);
    }
};