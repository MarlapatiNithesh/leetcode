class Solution{
public:
static const int MOD=1e9+7;

int countVowelPermutation(int n){

int dp[20001][6];
memset(dp,-1,sizeof(dp));

auto dfs=[&](auto& self,int idx,int prev)->int{

if(idx>=n)return 1;

if(prev!=-1&&dp[idx][prev]!=-1)
return dp[idx][prev];

int ans=0;

for(int i=1;i<=5;i++){

if(prev==-1){
ans=(ans+self(self,idx+1,i))%MOD;
}

else if(prev==1){
if(i==2)
ans=(ans+self(self,idx+1,i))%MOD;
}

else if(prev==2){
if(i==1||i==3)
ans=(ans+self(self,idx+1,i))%MOD;
}

else if(prev==3){
if(i!=3)
ans=(ans+self(self,idx+1,i))%MOD;
}

else if(prev==4){
if(i==3||i==5)
ans=(ans+self(self,idx+1,i))%MOD;
}

else if(prev==5){
if(i==1)
ans=(ans+self(self,idx+1,i))%MOD;
}
}

if(prev==-1)return ans;

return dp[idx][prev]=ans;
};

return dfs(dfs,0,-1);
}
};