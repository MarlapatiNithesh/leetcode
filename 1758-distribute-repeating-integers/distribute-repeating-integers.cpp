class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        int n=quantity.size();
        vector<int>fr(1e5+1,0);
        for(auto x:nums)fr[x]++;
        vector<int>org;
        for(auto it:fr){
            if(it>0){
                org.push_back(it);
            }
        }
        int m=org.size();
        int done=(1<<n)-1;
        vector<int>sum(1<<n,0);
        for(int mask=1;mask<=done;mask++){
            int bit=__builtin_ctz(mask);
            int prev=mask^(1<<bit);
            sum[mask]=sum[prev]+quantity[bit];
        }
        int dp[51][1<<n];
        memset(dp,-1,sizeof(dp));
        auto dfs=[&](auto& slef,int idx,int mask)->bool{
            if(mask==done){
                return true;
            }
            if(idx>=m)return false;
            if(dp[idx][mask]!=-1)return dp[idx][mask];
            if(slef(slef,idx+1,mask)){
                return dp[idx][mask]=1;
            }
            int rem=done^mask;
            for(int sub=rem;sub;sub=(sub-1) & rem){
                int need=sum[sub];
                if(need<=org[idx]){
                    if(slef(slef,idx+1,sub | mask)){
                        return dp[idx][mask]=1;
                    }
                }
            }
            return dp[idx][mask]=0;
        };
        return dfs(dfs,0,0);
    }
};