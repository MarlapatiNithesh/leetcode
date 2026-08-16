class Solution {
public:
    int findMaxForm(vector<string>& strs,int m,int n) {
        vector<pair<int,int>>cnt;
        for(auto it:strs){
            int cnt0=0,cnt1=0;
            for(int ch:it){
                if(ch=='0')cnt0++;
                else cnt1++;
            }
            cnt.push_back({cnt0,cnt1});
        }

        vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));

        auto dfs=[&](auto& self,int idx,int m1,int n1)->int{
            if(idx>=strs.size())return 0;
            if(dp[idx][m1][n1]!=-1)return dp[idx][m1][n1];

            int cnt0=cnt[idx].first,cnt1=cnt[idx].second;
            int take=0,notTake=0;


            if(m1>=cnt0&&n1>=cnt1){
                take=1+self(self,idx+1,m1-cnt0,n1-cnt1);
            }
            notTake=self(self,idx+1,m1,n1);


            return dp[idx][m1][n1]=max(take,notTake);
        };

        return dfs(dfs,0,m,n);
    }
};