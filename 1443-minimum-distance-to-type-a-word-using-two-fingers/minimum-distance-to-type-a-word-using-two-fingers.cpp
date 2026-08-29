class Solution{
public:
    static vector<vector<int>>wd;

    static void init(){
        wd={{0,1,2,3,4,5},
            {6,7,8,9,10,11},
            {12,13,14,15,16,17},
            {18,19,20,21,22,23},
            {24,25}};
    }

    int minimumDistance(string word){
        init();

        int dp[301][27][27];
        memset(dp,-1,sizeof(dp));

        int n=word.size();

        auto getIdxs=[&](int val)->pair<int,int>{
            int x=-1,y=-1;

            for(int i=0;i<5;i++){
                for(int j=0;j<wd[i].size();j++){
                    if(wd[i][j]==val){
                        x=i;
                        y=j;
                        break;
                    }
                }

                if(x!=-1 && y!=-1)break;
            }

            return {x,y};
        };

        auto dfs=[&](auto& slef,int idx,int prev1,int prev2)->int{
            if(idx>=n)return 0;

            if(dp[idx][prev1+1][prev2+1]!=-1)
                return dp[idx][prev1+1][prev2+1];

            int tt1=INT_MAX,tt2=INT_MAX;

            if(prev1==-1){
                tt1=slef(slef,idx+1,word[idx]-'A',prev2);
            }

            if(prev1!=-1 && prev2==-1){
                auto it=getIdxs(word[idx]-'A');
                auto it1=getIdxs(prev1);

                tt1=abs(it.first-it1.first)+abs(it.second-it1.second)
                    +slef(slef,idx+1,word[idx]-'A',prev2);

                tt2=slef(slef,idx+1,prev1,word[idx]-'A');
            }

            if(prev1!=-1 && prev2!=-1){
                auto it=getIdxs(word[idx]-'A');
                auto it1=getIdxs(prev1);
                auto it2=getIdxs(prev2);

                tt1=abs(it.first-it1.first)+abs(it.second-it1.second)
                    +slef(slef,idx+1,word[idx]-'A',prev2);

                tt2=abs(it.first-it2.first)+abs(it.second-it2.second)
                    +slef(slef,idx+1,prev1,word[idx]-'A');
            }

            return dp[idx][prev1+1][prev2+1]=min(tt1,tt2);
        };

        return dfs(dfs,0,-1,-1);
    }
};

vector<vector<int>>Solution::wd;