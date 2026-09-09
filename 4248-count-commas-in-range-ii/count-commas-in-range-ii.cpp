class Solution {
public:
    using ll = long long;

    long long countCommas(long long n) {
        ll base = 1e3;
        if(base > n) return 0;
        ll ans = 0;
        ll j = 1;
        if(n < 1e6){
            ans += (n - base + 1) * j;
            return ans;
        }
        ans += (1e6 - base) * j;
        for(ll i = 1e6; i <= n; i *= 1000){
            j++;
            ll next = i * 1000;
            if(n < next){
                ans += (n - i + 1) * j;
                break;
            } 
            else{
                ans += (next - i) * j;
            }
        }
        return ans;
    }
};