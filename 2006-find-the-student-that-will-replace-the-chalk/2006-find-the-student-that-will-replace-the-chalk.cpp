class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long long>prefixSum(n);
        prefixSum[0] = chalk[0];
        for(int i=1; i<n; i++) prefixSum[i] = (long long) chalk[i] + prefixSum[i-1];
        k %= prefixSum[n-1]; // totalSum
        for(int i=0; i<n; i++){
            if(k < prefixSum[i]) return i;
        }
        return -1;
    }
};