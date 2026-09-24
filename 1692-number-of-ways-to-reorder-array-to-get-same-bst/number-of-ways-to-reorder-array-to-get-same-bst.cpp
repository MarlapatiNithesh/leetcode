class Solution {
public:
    const int MOD=1e9+7;
    vector<long long> fact,invFact;

    long long MODPow(long long base,long long exp){
        long long res=1;
        while(exp){
            if(exp&1) res=res*base%MOD;
            base=base*base%MOD;
            exp>>=1;
        }
        return res;
    }

    long long dfs(vector<int> nums){
        int n=nums.size();
        if(n<=2) return 1;

        vector<int> l,r;
        int rt=nums[0];

        for(int i=1;i<n;i++){
            if(nums[i]<rt) l.push_back(nums[i]);
            else r.push_back(nums[i]);
        }

        long long left=dfs(l);
        long long right=dfs(r);

        long long ways=fact[n-1];
        ways=ways*invFact[l.size()]%MOD;
        ways=ways*invFact[r.size()]%MOD;

        return ways*left%MOD*right%MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n=nums.size();

        fact.assign(n+1,1);
        invFact.assign(n+1,1);

        for(int i=1;i<=n;i++)
            fact[i]=fact[i-1]*i%MOD;

        invFact[n]=MODPow(fact[n],MOD-2);

        for(int i=n-1;i>=0;i--)
            invFact[i]=invFact[i+1]*(i+1)%MOD;

        return (dfs(nums)-1+MOD)%MOD;
    }
};