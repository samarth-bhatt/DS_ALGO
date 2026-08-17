class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxi = INT_MIN;
        int ans = 0;
        for(const int &i: lights) maxi = max(maxi, i);
        for(auto &i: arrivalTime){
            i %= period;
            if(i >= maxi) ans = max(ans, period - i);
        }
        return ans;
    }
};