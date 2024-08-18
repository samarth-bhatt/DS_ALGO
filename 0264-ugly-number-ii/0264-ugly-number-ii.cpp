class Solution {
public:
    int nthUglyNumber(int n) {
        long long ugly = 1;
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        unordered_set<long long>visited;
        pq.push(1);
        visited.insert(1);
        for(int i=1; i<=n; i++){
            ugly = pq.top();
            pq.pop();
            for(auto &j: {2,3,5}){
                if(visited.count(ugly*j)) continue;
                pq.push(ugly*j);
                visited.insert(ugly*j);
            }
        }
        return (int)ugly;
    }




/*
    // Approach 2: O(~ n^2 - TLE)
    bool isUgly(int num, unordered_set<int> &ugly){
        if(ugly.count(num) > 0) return true;
        int original = num;
        while(num%2 == 0) num /= 2;
        while(num%3 == 0) num /= 3;
        while(num%5 == 0) num /= 5;
        if(num == 1){
            ugly.insert(original);
            return true;
        }
        return false;
    }
    int nthUglyNumber(int n) {
        if(n == 1) return 1;
        int count = 1;
        int ans = 1;
        unordered_set<int> ugly;
        while(count != n){
            ans++;
            if(isUgly(ans, ugly)) count++;
        }
        return ans;
    }
*/
};