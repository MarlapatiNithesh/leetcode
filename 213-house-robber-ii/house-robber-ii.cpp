class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];

        auto dfs=[&](int l,int r)->int{
            int a=0,b=0;
            for(int i=l;i<=r;i++){
                int c=max(nums[i]+a,b);
                a=b;
                b=c;
            }
            return b;
        };

        return max(dfs(0,n-2),dfs(1,n-1));
    }
};