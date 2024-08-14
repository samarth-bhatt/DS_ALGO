class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;
        int nonZeroIdx = 0;
        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                nums[nonZeroIdx] = nums[i];
                nonZeroIdx++;
            }
        }
        int i=0;
        int zeroCnt = n - nonZeroIdx;
        while(zeroCnt--){ nums[n - 1 - i] = 0; i++;}
    }
};