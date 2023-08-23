class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefix(n);
        prefix[0] = nums[0];
        for(int i=1; i<n; i++) prefix[i] = prefix[i-1] + nums[i];
        unordered_map<int, int> prefixFreq;  // Storing prefix sums and their frequencies
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(prefix[i] == k){
                ans++;
            }
            if(prefixFreq.find(prefix[i] - k) != prefixFreq.end()){
                ans += prefixFreq[prefix[i] - k];
            }
            prefixFreq[prefix[i]]++;  
            // Incrementing the frequency of the current prefix sum
        }
        return ans;
    }
};