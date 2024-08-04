class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>curr(n,1);
        int largest = INT_MIN;
        for(int ind=0; ind<n; ind++){
            for(int prev=0; prev<ind; prev++){
                if(nums[ind] > nums[prev] && 1 + dp[prev] > dp[ind]){
                    dp[ind] = 1 + dp[prev];
                    curr[ind] = curr[prev]; //inherit
                }
                else if(nums[ind] > nums[prev] && 1 + dp[prev] == dp[ind]){
                    curr[ind] += curr[prev]; //increase
                }
            }
            largest = max(largest, dp[ind]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            if(dp[i] == largest) ans += curr[i];
        }
        return ans;
    }
};