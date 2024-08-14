class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;
        int cnt_zero = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                int j = i+1;
                while(j<n && nums[j] == 0) j++;
                if(j == n) return;
                swap(nums[i], nums[j]);
            }
        }
    }
};