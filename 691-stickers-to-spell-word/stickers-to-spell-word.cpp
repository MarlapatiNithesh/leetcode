class Solution{
public:
    int minStickers(vector<string>& stickers,string target){
        int n=stickers.size();
        int m=target.size();

        vector<vector<int>>fr(n,vector<int>(26));

        for(int i=0;i<n;i++){
            for(auto ch:stickers[i]){
                fr[i][ch-'a']++;
            }
        }

        for(auto ch:target){
            int f=0;
            for(auto it:fr){
                if(it[ch-'a']){
                    f=1;
                    break;
                }
            }
            if(!f)return -1;
        }

        vector<vector<int>>dp(n+1,vector<int>(1<<m,-1));

        auto dfs=[&](auto& slef,int idx1,int idx2)->int{
            if(idx2==(1<<m)-1)return 0;

            if(idx1>=n)return 1e9;

            if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];

            int nt=slef(slef,idx1+1,idx2);

            vector<int>cnt=fr[idx1];
            int mask=idx2;

            for(int j=0;j<m;j++){
                if(mask&(1<<j))continue;

                if(cnt[target[j]-'a']){
                    cnt[target[j]-'a']--;
                    mask|=(1<<j);
                }
            }

            int tt=1e9;

            if(mask!=idx2){
                tt=1+slef(slef,idx1,mask);
            }

            return dp[idx1][idx2]=min(nt,tt);
        };

        int ans=dfs(dfs,0,0);

        return ans>=1e9?-1:ans;
    }
};