class Solution {
public:
    int minimumSum(int n, int k) {
        int ans = 0;  // ans stores the sum
        unordered_set<int>s;
        int smallest = 1;
        while(n--){
            if(s.count(k - smallest) > 0){
                smallest++;
                n++;
                continue;
            }
            s.insert(smallest);
            ans += smallest++;
        }
        return ans;
    }
};