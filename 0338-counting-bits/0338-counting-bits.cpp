class Solution {
public:
    vector<int> countBits(int n) {
        // 0 - 0
        // 1 - 1
        // 2 - 10
        // 3 - 11
        // 4 - 100
        // 5 - 101
        vector<int>dp(n+1);
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            if((i& (i-1)) == 0) dp[i] = 1;
            else dp[i] = (i%2) ? dp[i >> 1] + 1 : dp[i >> 1];
        }
        return dp;
    }
};