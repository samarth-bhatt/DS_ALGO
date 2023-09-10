class Solution {
public:
    const int MOD = 1e9 + 7;
    int countOrders(int n) {
        long long ans = 1;
        for(int i=1; i<=n; i++) ans = (ans * i) % MOD;
        for(int i=1; i<2*n; i+=2) ans = (ans * i) % MOD;
        return ans;
    }
};