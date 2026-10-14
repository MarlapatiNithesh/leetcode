class Solution {
    public String maxSumOfSquares(int num, int sum) {
        StringBuilder ans=new StringBuilder();
        for(int i=0;i<num;i++){
            for(int j=9;j>=0;j--){
                if(sum>=j){
                    sum-=j;
                    ans.append(j);
                    break;
                }
            }
        }
        return sum==0?ans.toString():"";
    }
}