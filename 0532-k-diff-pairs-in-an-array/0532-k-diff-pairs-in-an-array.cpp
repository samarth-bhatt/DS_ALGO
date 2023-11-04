class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k == 0){
            unordered_map<int, int>freq;
            for(int &i: nums) freq[i]++;
            int cnt = 0;
            for(auto &i: freq) if(i.second>1) cnt++;
            return cnt;
        }
        int cnt = 0;
        unordered_set<int>occ(nums.begin(), nums.end());
        unordered_set<int>unique(nums.begin(), nums.end());
        for(int i: unique){
            if(occ.find(i+k) != occ.end()) cnt ++;
        }
        return cnt;
    }
};