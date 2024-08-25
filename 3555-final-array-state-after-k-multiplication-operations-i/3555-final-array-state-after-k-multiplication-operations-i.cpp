class Solution {
public:
    static bool comp(pair<int, int> &p1, pair<int, int> &p2){
        return p1.second < p2.second;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(int i=0; i<nums.size(); i++) pq.push({nums[i], i});
        while(k--){
            pair<int, int> smallest = pq.top();
            pq.pop();
            smallest.first *= multiplier;
            pq.push({smallest});
        }
        vector<pair<int, int>>ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        sort(ans.begin(), ans.end(), comp);
        vector<int>finalAns;
        for(const pair<int, int> &p: ans) finalAns.push_back(p.first);
        return finalAns;
    }
};