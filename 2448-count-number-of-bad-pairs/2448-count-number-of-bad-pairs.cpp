typedef long long ll;
class Solution {
public:
    ll countBadPairs(vector<int>& nums) {
        ll n = nums.size();
        ll cnt = 0;
        if(n%2) cnt = ((n-1)/2)*n;
        else cnt = (n/2)*(n-1);
        unordered_map<ll, ll>freq;
        for(int i=0; i<n; i++) freq[nums[i] - i]++;
        for(pair<ll, ll> i: freq) if(i.second >= 2) cnt -= (i.second)*(i.second-1)/2;   
        return cnt;
    }
};