class Solution {
public:
    int evenDigitSum(int n){
        int dsum = 0;
        for(int i=n; i>0; i/=10) dsum += i%10;
        return dsum%2 == 0;
    }
    int countEven(int num) {
        int count = 0;
        for(int i=num; i>0; i--) if(evenDigitSum(i)) count++;
        return count;
    }
};