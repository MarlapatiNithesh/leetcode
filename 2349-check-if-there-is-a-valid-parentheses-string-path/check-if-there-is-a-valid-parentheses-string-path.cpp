class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();
        map<string,bool> dp;
        auto dfs=[&](auto &self,int i,int j,int bal)->bool{
            if(grid[i][j]=='(') bal++;
            else bal--;
            if(bal<0) return false;
            if(i==n-1 && j==m-1)
                return bal==0;

            string key=to_string(i)+"#"+to_string(j)+"#"+to_string(bal);
            if(dp.count(key)) return dp[key];

            if(i+1<n && self(self,i+1,j,bal)) return dp[key]=true;
            if(j+1<m && self(self,i,j+1,bal)) return dp[key]=true;

            return dp[key]=false;
        };

        if((n+m-1)&1) return false;
        return dfs(dfs,0,0,0);
    }
};