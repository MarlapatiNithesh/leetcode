class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=scores.size();
        vector<pair<int,int>>a;
        for(int i=0;i<n;i++)a.push_back({ages[i],scores[i]});
        sort(a.begin(),a.end());
        vector<int>dp(n,-1);
        int ans=0;
        for(int i=0;i<n;i++){
            int sc=a[i].second;
            dp[i]=a[i].second;
            for(int j=0;j<i;j++){
                if(a[j].second<=a[i].second){
                    dp[i]=max(dp[i],sc+dp[j]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};