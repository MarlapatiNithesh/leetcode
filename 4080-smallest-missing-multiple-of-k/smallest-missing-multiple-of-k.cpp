class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=1;
        for(int i=0;i<n;i++){
            if(nums[i]%k==0){
                if(cnt==nums[i]/k)cnt++;
            }
        }
        return cnt*k;
    }
};