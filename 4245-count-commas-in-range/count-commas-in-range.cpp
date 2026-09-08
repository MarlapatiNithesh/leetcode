class Solution {
public:
    int countCommas(int n) {
        int base=1000;
        if(n-base<0) return 0;
        return n-base+1;
    }
};