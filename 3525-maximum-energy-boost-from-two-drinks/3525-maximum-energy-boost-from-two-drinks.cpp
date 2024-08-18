class Solution {
public:
    long long helper(vector<int>& energyDrinkA, vector<int>& energyDrinkB, vector<vector<long long>> &dp, int ind, int prev, int n){
        if(ind >= n) return 0;
        if(dp[ind][prev] != -1) return dp[ind][prev];
        // base case
        long long ans = LONG_MIN;
        if(prev == 0){
            ans = max(helper(energyDrinkA, energyDrinkB, dp, ind+1, 1, n) + energyDrinkA[ind], helper(energyDrinkA, energyDrinkB, dp, ind+1, 2, n) + energyDrinkB[ind]);
        }
        else if(prev == 1){
            long long pick = energyDrinkA[ind] + helper(energyDrinkA, energyDrinkB, dp, ind+1, 1, n);
            long long notPick = helper(energyDrinkA, energyDrinkB, dp, ind+1, 2, n);
            ans = max(pick, notPick);
        }
        else if(prev == 2){
            long long pick = energyDrinkB[ind] + helper(energyDrinkA, energyDrinkB, dp, ind+1, 2, n);
            long long notPick = helper(energyDrinkA, energyDrinkB, dp, ind+1, 1, n);
            ans = max(pick, notPick);
        }
        return dp[ind][prev] = ans; 
    }
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<vector<long long>>dp(n, vector<long long>(3, -1));
        return helper(energyDrinkA, energyDrinkB, dp, 0, 0, n);
    }
};