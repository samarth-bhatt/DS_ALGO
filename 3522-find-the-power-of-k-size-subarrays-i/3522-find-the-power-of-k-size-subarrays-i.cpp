class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>results(n-k+1);
        for(int i=0; i<n-k+1; i++){
            int maxi = nums[i];
            for(int j=i+1; j<i+k; j++){
                if(nums[j-1] > nums[j] || nums[j] != nums[j-1] + 1){
                    maxi = -1;
                    break;
                } else{
                    maxi++;
                }
            }
            results[i] = maxi;
        }
        return results;
    }
};