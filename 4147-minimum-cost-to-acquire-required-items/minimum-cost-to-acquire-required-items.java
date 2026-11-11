
class Solution {
    public long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(costBoth>=cost1+cost2){
            return (long) cost1*need1+(long)cost2*need2;
        }
        long ans=(long)costBoth*Math.min(need1,need2);
        if(need1>need2){
            ans+=(long)(need1-need2)*Math.min(cost1,costBoth);
        }else ans+=(long)(need2-need1)*Math.min(cost2,costBoth);
        return ans;
    }
}
