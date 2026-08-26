class Solution { 
public: 
    int findRotateSteps(string ring, string key) { 
        int n=ring.size(),m=key.size(); 
        
        int dp[101][101];
        memset(dp,-1,sizeof(dp));
        
        auto dfs=[&](auto& slef,int idx1,int idx2)->int{ 
            
            if(idx2>=m)return 0; 
            
            if(dp[idx1][idx2]!=-1)
                return dp[idx1][idx2];
            
            int tt=INT_MAX,ntc=INT_MAX,nta=INT_MAX; 
            
            for(int i=1;i<=n;i++){
                
                int next1=(idx1+i)%n;
                
                if(ring[next1]==key[idx2]){
                    
                    int temp1=slef(slef,next1,idx2+1);
                    
                    if(temp1!=INT_MAX){
                        ntc=min(ntc,i+1+temp1);
                    }
                }
                
                
                int next2=(idx1-i+n)%n;
                
                if(ring[next2]==key[idx2]){
                    
                    int temp2=slef(slef,next2,idx2+1);
                    
                    if(temp2!=INT_MAX){
                        nta=min(nta,i+1+temp2);
                    }
                }
            }
            
            
            if(ring[idx1]==key[idx2]){ 
                
                int temp=slef(slef,idx1,idx2+1); 
                
                if(temp!=INT_MAX)
                    tt=1+temp; 
            } 
            
            return dp[idx1][idx2]=min({tt,ntc,nta}); 
        }; 
        
        return dfs(dfs,0,0); 
    } 
};