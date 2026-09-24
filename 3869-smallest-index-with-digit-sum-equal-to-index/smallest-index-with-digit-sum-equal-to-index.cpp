class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            int s=0;
            while(val>0){
                s+=val%10;
                val/=10;
            }
            if(s==i)return i;
        }
        return -1;
    }
};