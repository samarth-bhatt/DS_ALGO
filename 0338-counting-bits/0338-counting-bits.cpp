class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1);
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            if((i& (i-1)) == 0) dp[i] = dp[i-1] - log2(i) + 1;
            else dp[i] = (i%2) ? dp[i-1] + 1 : dp[i/2];
        }
        return dp;
    }
};