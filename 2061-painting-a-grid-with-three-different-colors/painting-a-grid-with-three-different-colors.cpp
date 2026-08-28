class Solution{
public:
    static const int MOD=1000000007;

    vector<string>gen;

    void generate(string s,int prev,int m){
        if(s.size()==m){
            gen.push_back(s);
            return;
        }

        for(int i=0;i<3;i++){
            if(prev==i)continue;
            generate(s+char('0'+i),i,m);
        }
    }

    int colorTheGrid(int m,int n){

        generate("",-1,m);

        int m1=gen.size();

        vector<vector<int>>dp(n,vector<int>(m1+1,-1));

        auto dfs=[&](auto& self,int idx,int prev)->int{
            if(idx==n)return 1;

            if(dp[idx][prev+1]!=-1)
                return dp[idx][prev+1];

            long long ans=0;

            for(int i=0;i<m1;i++){

                if(prev!=-1){

                    bool bad=false;

                    for(int j=0;j<m;j++){
                        if(gen[i][j]==gen[prev][j]){
                            bad=true;
                            break;
                        }
                    }

                    if(bad)continue;
                }

                ans=(ans+self(self,idx+1,i))%MOD;
            }

            return dp[idx][prev+1]=ans;
        };

        return dfs(dfs,0,-1);
    }
};