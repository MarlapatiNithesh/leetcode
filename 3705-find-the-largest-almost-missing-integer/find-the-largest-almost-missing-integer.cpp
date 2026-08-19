class Solution {
public:
    int largestInteger(vector<int>& nums,int k) {
        int n=nums.size();
        if(k==n){
            int mx=*max_element(nums.begin(),nums.end());
            return mx;
        }
        map<int,int>mp;
        for(int i=0;i<=n-k;i++){
            for(int j=i;j<i+k;j++){
                mp[nums[j]]++;
            }
        }

        int ans=-1;
        for(auto it:mp){
            if(it.second==1)ans=max(ans,it.first);
        }
        return ans==-1?-1:ans;
    }
};