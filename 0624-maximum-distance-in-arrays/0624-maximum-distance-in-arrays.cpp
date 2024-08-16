class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int minVal = arrays[0][0];
        int maxVal = arrays[0][arrays[0].size()-1];
        // int max1 = -1e8, max2 = -1e8, max3 = -1e8, max4 = -1e8;
        int maxAns = INT_MIN;
        for(int i=1; i<n; i++){
            // int mini = arrays[i-1][0];
            // int maxi = arrays[i-1][arrays[i-1].size()-1];
            int minj = arrays[i][0];
            int maxj = arrays[i][arrays[i].size()-1];
            // max1 = max(max1, abs(mini - minj));
            // max2 = max(max2, abs(mini - maxj));
            // max3 = max(max3, abs(maxi - minj));
            // max4 = max(max4, abs(maxi - maxj));
            // maxAns = max({maxAns, max1, max2, max3, max4});
            maxAns = max({maxAns, abs(maxVal - minj), abs(minVal - maxj)});
            minVal = min(minVal, minj);
            maxVal = max(maxVal, maxj);
        }
        return maxAns;
    }
};