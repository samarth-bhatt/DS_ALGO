class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string num = "";
        for(char &i: s){
            if(i == '0') continue;
            num += i;
        }
        if(num.length() == 0){
            return 0;
        }
        long long sum = 0;
        for(char &i: num){
            sum += i - '0';
        }
        return (long long) sum * stoll(num);
    }
};