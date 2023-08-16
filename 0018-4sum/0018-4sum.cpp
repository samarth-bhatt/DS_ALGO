class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-3; i++){
            if(i>0 && nums[i] == nums[i-1]) continue; // skipping duplicates 
            for(int j=i+1; j<n-2; j++){
                if(j>i+1 && nums[j] == nums[j-1]) continue; // skipping duplicates
                int low = j+1;
                int high = n-1;
                long long remainingTarget = (long long) target - (long long) nums[i] - (long long) nums[j];
                while(low < high){
                    if(nums[low] + nums[high] == remainingTarget){
                        ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                        // skipping duplicates
                        while (low < high && nums[low] == nums[low + 1]) low++;
                        while (low < high && nums[high] == nums[high - 1]) high--;
                        low++;
                        high--;
                    } else if(nums[low] + nums[high] < remainingTarget){
                        low++;
                    } else{
                        high--;
                    }
                }
            }
        }
        return ans;
    }
};