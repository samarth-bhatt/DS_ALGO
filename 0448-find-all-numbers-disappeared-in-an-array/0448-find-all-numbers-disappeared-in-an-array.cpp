class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int>appeared;
        for(const int &num: nums) appeared.insert(num);
        vector<int>ans;
        for(int i=1; i<=nums.size(); i++){
            if(appeared.count(i) == 0) ans.push_back(i);
        }
        return ans;
    }
};