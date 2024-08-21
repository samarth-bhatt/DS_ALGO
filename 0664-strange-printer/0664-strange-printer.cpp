class Solution {
public:
    int helper(int l, int r, string &s, vector<vector<int>> &dp){
        if(dp[l][r] != -1) return dp[l][r];
        if(l == r) return 1;
        if(l > r) return 0;
        int i=l+1;
        while(i <= r && s[i] == s[l]) i++;
        if(i == r+1) return 1;
        int option1 = 1 + helper(i, r, s, dp);
        int option2 = INT_MAX;
        for(int j=i; j<=r; j++){
            if(s[j] == s[l]) option2 = min(option2, helper(i, j-1, s, dp) + helper(j, r, s, dp));
        }
        return dp[l][r] = min(option1, option2);
    }
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return helper(0, n-1, s, dp);        
    }
};