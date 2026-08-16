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

        int sz=strs.size();
        vector<vector<vector<int>>>dp(sz,vector<vector<int>>(m+1,vector<int>(n+1,0)));

        int cnt0=cnt[0].first,cnt1=cnt[0].second;
        for(int m1=cnt0;m1<=m;m1++){
            for(int n1=cnt1;n1<=n;n1++){
                dp[0][m1][n1]=1;
            }
        }

        for(int i=1;i<sz;i++){
            cnt0=cnt[i].first;
            cnt1=cnt[i].second;

            for(int m1=0;m1<=m;m1++){
                for(int n1=0;n1<=n;n1++){
                    dp[i][m1][n1]=dp[i-1][m1][n1];

                    if(m1>=cnt0&&n1>=cnt1){
                        dp[i][m1][n1]=max(dp[i][m1][n1],
                            1+dp[i-1][m1-cnt0][n1-cnt1]);
                    }
                }
            }
        }

        return dp[sz-1][m][n];
    }
};