class Node{
    int idx1;
    int idx2;
    long val;
    int par;
    Node(int idx1,int idx2,long val,int par){
        this.idx1=idx1;
        this.idx2=idx2;
        this.val=val;
        this.par=par;
    }
}
class Solution{
    public long minCost(int m,int n,int[][] penalty){
        long[][][] dp=new long[m][n][2];
        for(long[][] r1:dp){
            for(long[] r2:r1){
                Arrays.fill(r2,Long.MAX_VALUE);
            }
        }

        PriorityQueue<Node>pq=new PriorityQueue<>(Comparator.comparingLong((Node x)->x.val).thenComparingInt(x->x.par));

        dp[0][0][1]=1;
        pq.offer(new Node(0,0,1,1));

        while(!pq.isEmpty()){
            Node v=pq.poll();
            int idx1=v.idx1,idx2=v.idx2,par=v.par;
            long val=v.val;

            if(val>dp[idx1][idx2][par])continue;

            if(idx1==m-1&&idx2==n-1)return val;

            long cost=val+penalty[idx1][idx2];

            if(dp[idx1][idx2][par^1]>cost){
                dp[idx1][idx2][par^1]=cost;
                pq.offer(new Node(idx1,idx2,cost,par^1));
            }

            if(par==1){
                // odd action: right or down is preferred

                if(idx1+1<m){
                    cost=val+(long)(idx1+2)*(idx2+1);
                    if(dp[idx1+1][idx2][par^1]>cost){
                        dp[idx1+1][idx2][par^1]=cost;
                        pq.offer(new Node(idx1+1,idx2,cost,par^1));
                    }
                }

                if(idx2+1<n){
                    cost=val+(long)(idx1+1)*(idx2+2);
                    if(dp[idx1][idx2+1][par^1]>cost){
                        dp[idx1][idx2+1][par^1]=cost;
                        pq.offer(new Node(idx1,idx2+1,cost,par^1));
                    }
                }

                if(idx1-1>=0){
                    cost=val+(long)idx1*(idx2+1)+penalty[idx1][idx2];
                    if(dp[idx1-1][idx2][par^1]>cost){
                        dp[idx1-1][idx2][par^1]=cost;
                        pq.offer(new Node(idx1-1,idx2,cost,par^1));
                    }
                }

                if(idx2-1>=0){
                    cost=val+(long)(idx1+1)*idx2+penalty[idx1][idx2];
                    if(dp[idx1][idx2-1][par^1]>cost){
                        dp[idx1][idx2-1][par^1]=cost;
                        pq.offer(new Node(idx1,idx2-1,cost,par^1));
                    }
                }
            }else{
                // even action: left or up is preferred

                if(idx1-1>=0){
                    cost=val+(long)idx1*(idx2+1);
                    if(dp[idx1-1][idx2][par^1]>cost){
                        dp[idx1-1][idx2][par^1]=cost;
                        pq.offer(new Node(idx1-1,idx2,cost,par^1));
                    }
                }

                if(idx2-1>=0){
                    cost=val+(long)(idx1+1)*idx2;
                    if(dp[idx1][idx2-1][par^1]>cost){
                        dp[idx1][idx2-1][par^1]=cost;
                        pq.offer(new Node(idx1,idx2-1,cost,par^1));
                    }
                }

                if(idx1+1<m){
                    cost=val+(long)(idx1+2)*(idx2+1)+penalty[idx1][idx2];
                    if(dp[idx1+1][idx2][par^1]>cost){
                        dp[idx1+1][idx2][par^1]=cost;
                        pq.offer(new Node(idx1+1,idx2,cost,par^1));
                    }
                }

                if(idx2+1<n){
                    cost=val+(long)(idx1+1)*(idx2+2)+penalty[idx1][idx2];
                    if(dp[idx1][idx2+1][par^1]>cost){
                        dp[idx1][idx2+1][par^1]=cost;
                        pq.offer(new Node(idx1,idx2+1,cost,par^1));
                    }
                }
            }
        }

        return -1;
    }
}