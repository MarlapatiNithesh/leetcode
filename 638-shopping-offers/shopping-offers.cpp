class Solution {
public:
    int shoppingOffers(vector<int>& prices,vector<vector<int>>& special,vector<int>& req){
        int n=prices.size();
        map<pair<int,vector<int>>,int>dp;

        auto dfs=[&](auto& self,int idx,vector<int> req)->int{
            if(idx>=special.size()){
                int s=0;
                for(int i=0;i<n;i++)
                    s+=req[i]*prices[i];
                return s;
            }

            pair<int,vector<int>>key={idx,req};

            if(dp.count(key))
                return dp[key];

            int notTake=self(self,idx+1,req);

            bool ok=true;
            for(int i=0;i<n;i++){
                if(req[i]<special[idx][i]){
                    ok=false;
                    break;
                }
            }

            int take=INT_MAX;

            if(ok){
                for(int i=0;i<n;i++)
                    req[i]-=special[idx][i];

                take=self(self,idx,req)+special[idx][n];
            }

            return dp[key]=min(take,notTake);
        };

        return dfs(dfs,0,req);
    }
};