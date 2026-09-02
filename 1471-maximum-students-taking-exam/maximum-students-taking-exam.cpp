class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int n=seats.size();
        int m=seats[0].size();

        int dp[9][9][1<<8][1<<8];
        fill(&dp[0][0][0][0],
             &dp[0][0][0][0]+9*9*(1<<8)*(1<<8),-1);

        auto dfs=[&](auto& self,int idx1,int idx2,int pre_mask,int cur_mask)->int{

            if(idx2>=m){
                return self(self,idx1+1,0,cur_mask,0);
            }

            if(idx1>=n)return 0;

            if(dp[idx1][idx2][pre_mask][cur_mask]!=-1)
                return dp[idx1][idx2][pre_mask][cur_mask];

            int nt=self(self,idx1,idx2+1,pre_mask,cur_mask);

            int tt=INT_MIN;

            if(seats[idx1][idx2]=='.'){
                bool ok=true;

                if(idx2-1>=0 && (pre_mask&(1<<(idx2-1))))
                    ok=false;

                if(idx2+1<m && (pre_mask&(1<<(idx2+1))))
                    ok=false;

                if(idx2-1>=0 && (cur_mask&(1<<(idx2-1))))
                    ok=false;


                if(ok){
                    int temp=self(
                        self,
                        idx1,
                        idx2+1,
                        pre_mask,
                        cur_mask|(1<<idx2)
                    );

                    if(temp!=INT_MIN)
                        tt=1+temp;
                }
            }

            return dp[idx1][idx2][pre_mask][cur_mask]=max(nt,tt);
        };

        return dfs(dfs,0,0,0,0);
    }
};