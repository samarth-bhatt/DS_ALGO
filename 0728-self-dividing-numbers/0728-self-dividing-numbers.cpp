class Solution {
public:
    bool isSelfDividing(int num){
        int n = num;
        while(n){
            int digit = n%10;
            if(digit == 0 || num%digit) return false;
            n /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int i=left; i<=right; i++){
            if(isSelfDividing(i)) ans.push_back(i);
        }
        return ans;
    }
};