class Solution {
    private static int MOD=1000000007;
    long[] sumSeg,lazySeg,sqSeg;
    HashMap<Integer,Integer> lastIdx;
    private void lazyAddition(int idx,int l,int r,long val){
        long len=(r-l+1);
        sqSeg[idx]=(sqSeg[idx]+2*val*sumSeg[idx]+len*val*val)%MOD;
        sumSeg[idx]=(sumSeg[idx]+len*val)%MOD;
    }
    private void update(int start,int end,int idx,int l,int r,int val){
        if(lazySeg[idx]!=0){
            lazyAddition(idx,l,r,lazySeg[idx]);
            if(l!=r){
                lazySeg[2*idx+1]=(lazySeg[2*idx+1]+lazySeg[idx])%MOD;
                lazySeg[2*idx+2]=(lazySeg[2*idx+2]+lazySeg[idx])%MOD;
            }
            lazySeg[idx]=0;
        }
        if(l>end || r<start || l>r){
            return;
        }
        if(l>=start && r<=end){
            lazyAddition(idx,l,r,val);
            if(l!=r){
                lazySeg[2*idx+1]=(lazySeg[2*idx+1]+val)%MOD;
                lazySeg[2*idx+2]=(lazySeg[2*idx+2]+val)%MOD;
            }
            return;
        }
        int mid=l+(r-l)/2;
        update(start,end,2*idx+1,l,mid,val);
        update(start,end,2*idx+2,mid+1,r,val);
        sumSeg[idx]=(sumSeg[2*idx+1]+sumSeg[2*idx+2])%MOD;
        sqSeg[idx]=(sqSeg[2*idx+1]+sqSeg[2*idx+2])%MOD;
    }
    public int sumCounts(int[] nums) {
        int n=nums.length;
        sumSeg=new long[4*n];
        lazySeg=new long[4*n];
        sqSeg=new long[4*n];
        lastIdx=new HashMap<>();
        long res=0;
        for(int i=0;i<n;i++){
            int start=lastIdx.getOrDefault(nums[i],-1)+1;
            int end=i;
            update(start,end,0,0,n-1,1);
            res=(res+sqSeg[0])%MOD;
            lastIdx.put(nums[i],i);
        }
        return (int)res;
    }
}