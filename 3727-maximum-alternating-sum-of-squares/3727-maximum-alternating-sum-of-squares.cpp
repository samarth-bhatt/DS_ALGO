class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>vec = nums;
        for(int i=0; i<n; i++) vec[i] = abs(vec[i]);
        sort(vec.begin(),vec.end());
        long long ans = 0;
        for(int i=0; i<n/2; i++){
            ans += ((vec[n-1-i] * vec[n-1-i]) - (vec[i] * vec[i]));
        }
        if(n%2) ans += vec[n/2] * vec[n/2];
        return ans;
    }
};