class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int curr = (nums[0]%2) ? 1 : 0;
        for(int i=1; i<nums.size(); i++){
            if((nums[i]%2 && curr == 1) || (nums[i]%2 == 0 && curr == 0)) return false;
            curr = nums[i]%2;
        }
        return true;
    }
};