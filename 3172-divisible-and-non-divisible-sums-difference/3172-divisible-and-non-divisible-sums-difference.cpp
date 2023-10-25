class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalSum = 0, divisibleSum = 0;
        for(int i=1; i<=n; i++){
            if(i%m == 0) divisibleSum += i;
            totalSum += i;
        }
        // nonDivisibleSum = totalSum - divisibleSum
        return totalSum - 2 * divisibleSum;
    }
};