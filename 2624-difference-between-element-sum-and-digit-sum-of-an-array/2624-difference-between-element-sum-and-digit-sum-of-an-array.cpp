class Solution {
public:
    int sumOfDigits(int num){
        int sumOfDigit = 0;
        while(num){
            int temp = num%10;
            sumOfDigit += temp;
            num /= 10;
        }
        return sumOfDigit;
    }
    int differenceOfSum(vector<int>& nums) {
        int eleSum = 0;
        int digiSum = 0;
        for(int &i: nums){
            eleSum += i;
            digiSum += sumOfDigits(i);
        }
        return abs(eleSum - digiSum);
    }
};