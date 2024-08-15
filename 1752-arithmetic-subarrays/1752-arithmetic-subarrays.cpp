class Solution {
public:
    bool check(int left, int right, vector<int>&nums){
        vector<int>temp(right - left + 1);
        for(int i=left; i<=right; i++) temp[i-left] = nums[i];
        sort(temp.begin(), temp.end());
        int common_diff = temp[1] - temp[0]; 
        for(int i=1; i<right-left+1; i++) if(temp[i] - temp[i-1] != common_diff) return false;
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool>ans(n);
        for(int i=0; i<n; i++){
            ans[i] = (l == r) ? true : check(l[i], r[i], nums);
        }
        return ans;
    }
};