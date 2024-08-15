class Solution {
public:
    bool isValid(int num, vector<int> &nums, int k){
        int left = 0; // left element of pair
        int count = 0;
        for(int right=1; right<nums.size(); right++){
            while (nums[right] - nums[left] > num) left++;
            count += right - left;
            if(count >= k) return true;
        }
        return count >= k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // binary search;
        int low = 0; // min difference possible
        int high = nums[n - 1] - nums[0]; // max difference possible;
        // int k_largest = 0;
        while(low < high){
            int mid = low + (high - low)/2;
            if(isValid(mid, nums, k)){
                high = mid;
                // k_largest = min(k_largest, mid);
            } else{
                low = mid + 1;
            }
        }
        // return k_largest;
        return low;
    }
};