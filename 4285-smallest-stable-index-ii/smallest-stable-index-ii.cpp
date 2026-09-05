class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefmin(n);
        prefmin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            prefmin[i]=min(prefmin[i+1],nums[i]);
        }
        int mx=0;
        int ans=-1;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            if(mx-prefmin[i]<=k){
                return i;
            }
        }
        return -1;
    }
};