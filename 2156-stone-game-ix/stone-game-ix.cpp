class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n=stones.size();
        vector<int>fr(3,0);
        for(int i=0;i<n;i++){
            fr[stones[i]%3]++;
        }
        if(fr[0]%2==0){
            return (fr[1]>=1 && fr[2]>=1);
        }
        return abs(fr[1]-fr[2])>2;
    }
};