class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int miniPairSum = INT_MIN;
        for(int i=0; i<n/2; i++){
            miniPairSum = max(miniPairSum, nums[i] + nums[n-1-i]);
        }
        return miniPairSum;
    }
};