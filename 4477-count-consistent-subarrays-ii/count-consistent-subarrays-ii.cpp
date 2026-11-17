class Solution {
public:
    long long countConsistent(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>pref(n,vector<int>(20,-1));
        vector<vector<int>>suff(n,vector<int>(20,n));
        for(int i=0;i<n;i++){
            for(int j=0;j<20;j++){
                if(nums[i]&(1<<j)){
                    pref[i][j]=i==0?-1:pref[i-1][j];
                }else{
                    pref[i][j]=i;
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<20;j++){
                if(nums[i]&(1<<j)){
                    suff[i][j]=i==n-1?n:suff[i+1][j];
                }else{
                    suff[i][j]=i;
                }
            }
        }
        unordered_map<int,vector<int>>nxt;
        for(int i=n-1;i>=0;i--){
            nxt[nums[i]].push_back(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            int l=-1,r=n;
            for(int j=0;j<20;j++){
                if(nums[i]&(1<<j)){
                    l=max(l,pref[i][j]);
                    r=min(r,suff[i][j]);
                }
            }
            nxt[nums[i]].pop_back();
            if(!nxt[nums[i]].empty()){
                r=min(r,nxt[nums[i]].back());
            }
            ans+=1LL*(i-l)*(r-i);
        }
        // cout<<"pref-arrya:\n";
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<20;j++){
        //         cout<<pref[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"suff-array:\n";
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<20;j++){
        //         cout<<suff[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return ans;

    }
};