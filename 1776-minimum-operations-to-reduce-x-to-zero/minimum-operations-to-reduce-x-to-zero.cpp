class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int ans=INT_MAX;

        // only right + suffixes for case 2 and 3
        unordered_map<long long,pair<int,int>> mp;

        long long sum=0;

        for(int i=n-1;i>=0;i--){
            sum+=nums[i];

            if(!mp.count(sum)){
                mp[sum]={n-i,i};
            }

            // only right
            if(sum==x){
                ans=min(ans,n-i);
            }
        }

        // only left + left and right
        sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];

            // only left
            if(sum==x){
                ans=min(ans,i+1);
            }

            // left + right
            long long need=x-sum;

            if(mp.count(need)){
                int len=mp[need].first;
                int start=mp[need].second;

                if(start>i){
                    ans=min(ans,(i+1)+len);
                }
            }
        }

        return ans==INT_MAX ? -1 : ans;
    }
};