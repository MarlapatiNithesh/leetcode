class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        int n=stations.length;
        PriorityQueue<Integer>pq=new PriorityQueue<>(Collections.reverseOrder());
        int fuel=startFuel;
        int i=0;
        int st=0;
        while(fuel<target){
            while(i<n && stations[i][0]<=fuel){
                pq.offer(stations[i][1]);
                i++;
            }
            if(pq.isEmpty())return -1;
            fuel+=pq.poll();
            st++;
        }
        return st;
    }
}