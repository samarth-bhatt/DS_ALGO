class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        unordered_set<int>unique;
        for(int i=0; i<n; i++){
            for(int length=1; i+length<=n; length++){
                for(int j=i; j<i+length; j++){
                    unique.insert(nums[j]);
                }
                int uniqueEle = unique.size();
                sum += uniqueEle*uniqueEle;
                unique.clear();
            }
        }
        return sum;
    }
};