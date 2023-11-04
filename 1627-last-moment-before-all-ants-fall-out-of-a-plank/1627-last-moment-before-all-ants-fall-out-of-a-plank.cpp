class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxAns = 0;
        for(auto i:left)
            maxAns = max(maxAns, i);
        for(auto i: right)
            maxAns = max(maxAns, n-i);
        return maxAns;
    }
};