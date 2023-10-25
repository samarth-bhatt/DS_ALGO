class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            int cnt = 0;
            for(int j=0; j<32; j++){
                if(1<<j & i) cnt++;
            }
            if(cnt == k) ans += nums[i];
        }
        return ans;
    }
};