class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>smaller;
        vector<int>larger;
        int pivotCnt = 0;
        vector<int>ans(n);

        for(int i=0; i<n; i++){
            if(nums[i] < pivot) smaller.push_back(nums[i]);
            else if(nums[i] > pivot) larger.push_back(nums[i]);
            else pivotCnt++;
        }

        int counter = 0;
        for(int i=0; i<smaller.size(); i++) ans[counter++] = smaller[i];
        for(int i=0; i<pivotCnt; i++) ans[counter++] = pivot;
        for(int i=0; i<larger.size(); i++) ans[counter++] = larger[i];
        return ans;
    }
};











// rough
/*
        // int cntPivot = 0;
        // int i = -1;
        // for(int j=0; j<n; j++){
        //     if(nums[j] < pivot){
        //         i++;
        //         swap(nums[i], nums[j]);
        //     } else if(nums[j] == pivot) pivotCnt++;
        // }
        // swap(nums[i], nums[nums.size() - 1)
*/