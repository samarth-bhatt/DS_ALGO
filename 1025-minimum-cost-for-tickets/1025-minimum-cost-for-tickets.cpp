class Solution {
public:
    int helper(int ind, vector<int>& days, vector<int>& costs, int n, vector<int>&dp){
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int i;
        // for(i=ind; i<n && days[i]<days[ind]+1; i++);
        int oneDay = costs[0] + helper(ind + 1, days, costs, n, dp);
        for(i=ind; i<n && days[i]<days[ind]+7; i++);
        int oneWeek = costs[1] + helper(i, days, costs, n, dp);
        for(i=ind; i<n && days[i]<days[ind]+30; i++);
        int oneMonth = costs[2] + helper(i, days, costs, n, dp);
        return dp[ind] = min({oneDay, oneWeek, oneMonth});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n, -1);
        return helper(0, days, costs, n, dp);
    }
};