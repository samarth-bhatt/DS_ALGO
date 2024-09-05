class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int totSum = (n + m) * mean;
        int prevSum = 0;
        for(const int &s: rolls) prevSum += s;
        int missingSum = totSum - prevSum;
        vector<int>ans;
        if((double)missingSum / n > 6.0 || (double)missingSum / n < 1.0) return ans;
        for(int i=0; i<n; i++){
            ans.push_back(ceil(missingSum / (n-i)));
            missingSum -= ans[i];
        }
        return ans;
    }
};