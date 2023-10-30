class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        int n = num;
        while(n){
            int digit = n%10;
            if(num % digit == 0) count++;
            n /= 10;
        }
        return count;
    }
};