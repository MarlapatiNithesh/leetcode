class Solution {
public:
    int shoppingOffers(vector<int>& prices,vector<vector<int>>& special,vector<int>& req){
        int n=prices.size();

        auto dfs=[&](auto& self,int idx,int s)->int{
            if(idx>=special.size()){
                for(int i=0;i<n;i++)
                    s+=req[i]*prices[i];
                return s;
            }

            int notTake=self(self,idx+1,s);

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

                take=self(self,idx,s+special[idx][n]);
                for(int i=0;i<n;i++){
                    req[i]+=special[idx][i];
                }

            }
            return min(take,notTake);
        };

        return dfs(dfs,0,0);
    }
};