class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int cnt = 0;
        unordered_map<int, int>occ;
        for(int i: nums) occ[i]++;
        for(int i: nums){
            if(occ.find(i+k) != occ.end()) cnt += occ[i+k];
        }
        return cnt;
    }
};