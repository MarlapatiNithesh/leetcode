class Solution {
    public int minSwapsCouples(int[] row) {
        int n = row.length;
        Map<Integer,Integer>mp = new HashMap<>();

        for(int i=0;i<n;i++){
            mp.put(row[i],i);
        }

        int ans=0;

        for(int i=0;i<n;i+=2){
            int p = row[i];
            int partner = p ^ 1;

            if(row[i+1] != partner){
                int pos = mp.get(partner);

                int temp = row[i+1];
                row[i+1] = row[pos];
                row[pos] = temp;

                mp.put(row[pos],pos);
                mp.put(row[i+1],i+1);

                ans++;
            }
        }

        return ans;
    }
}