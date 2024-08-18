class Solution {
public:
    bool doesSatisfy(string str, int k){
        int cnt0 = 0, cnt1 = 0;
        for(int i=0; i<str.length(); i++){
            if(str[i] == '0') cnt0++;
            else cnt1++;
        }
        return (cnt0<=k || cnt1<=k);
    }
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<s.length(); j++){
                if(doesSatisfy(s.substr(i, n - j), k)) count++;
            }
        }
        return count;
    }
};