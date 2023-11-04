class FindSumPairs {
private:
    int sz1, sz2;
    vector<int>n1, n2;
    unordered_map<int, int>freqEle2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        sz1 = n1.size();
        sz2 = n2.size();
        for(int i: n2) freqEle2[i]++;
    }
    
    void add(int index, int val) {
        freqEle2[n2[index]]--;
        n2[index] += val;
        freqEle2[n2[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for(int i: n1){
            cnt += freqEle2[tot-i];
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */