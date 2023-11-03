class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int>ele(nums.begin(), nums.end());
        int cnt = 0;
        for(int i=0; i<nums.size()-2; i++){
            int number = nums[i];
            if(ele.count(number + diff) > 0 && ele.count(number + 2*diff) > 0) cnt++;
        }
        return cnt;
    }
};