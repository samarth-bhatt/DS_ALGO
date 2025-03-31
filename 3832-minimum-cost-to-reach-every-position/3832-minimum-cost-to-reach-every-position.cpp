class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int>ans(cost.size());
        int mini = INT_MAX;
        for(int i=0; i<cost.size(); i++){
            ans[i] = min(mini, cost[i]);
            mini = min(mini, cost[i]);
        }
        return ans;
    }
};