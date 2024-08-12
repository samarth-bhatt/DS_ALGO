class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    int n = 0;
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for(const int &i: nums){
            pq.push(i);
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > n) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */