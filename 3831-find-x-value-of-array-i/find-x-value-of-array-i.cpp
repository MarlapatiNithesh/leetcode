class Solution { 
public: 
    vector<long long> resultArray(vector<int>& nums, int k) { 
        int n=nums.size(); 

        for(int i=0;i<n;i++){ 
            nums[i]%=k; 
        } 

        vector<long long>ans(k,0); 

        for(int target=0;target<k;target++){ 
            vector<vector<long long>>dp(n,vector<long long>(k,-1)); 

            auto dfs=[&](auto& slef,int idx,int pd)->long long{ 
                if(idx>=n)return 0; 

                if(dp[idx][pd]!=-1)return dp[idx][pd]; 

                int nwpd=(1LL*pd*nums[idx])%k; 

                long long ans=0; 

                if(nwpd==target)ans++; 

                ans+=slef(slef,idx+1,nwpd); 

                return dp[idx][pd]=ans; 
            }; 

            for(int i=0;i<n;i++){ 
                ans[target]+=dfs(dfs,i,1%k); 
            } 
        } 

        return ans; 
    } 
};