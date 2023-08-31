class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int, vector<int>>pq(piles.begin(), piles.end());
        while(k--){
            int curr = pq.top();
            pq.pop();
            pq.push(ceil((float)curr/2));
        }
        int ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};