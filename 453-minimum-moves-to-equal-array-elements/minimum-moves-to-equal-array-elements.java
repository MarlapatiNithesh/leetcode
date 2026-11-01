class Solution {
    public int minMoves(int[] nums) {
        int mn=Integer.MAX_VALUE;
        for(int val:nums){
            mn=Math.min(mn,val);
        }
        int ans=0;
        for(int val:nums){
            ans+=val-mn;
        }
        return ans;
    }
}