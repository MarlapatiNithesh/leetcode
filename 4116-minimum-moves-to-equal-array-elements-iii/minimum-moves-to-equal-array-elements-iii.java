class Solution {
    public int minMoves(int[] nums) {
        int n=nums.length;
        Arrays.sort(nums);
        int md=nums[n-1];
        int ans=0;
        for(int val:nums)ans+=md-val;
        return ans;
    }
}