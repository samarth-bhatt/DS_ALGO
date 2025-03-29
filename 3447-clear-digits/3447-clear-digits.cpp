class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        int digits = 0;
        string ans;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i] >= '0' && s[i] <= '9'){
                digits++;
                continue;
            }
            if(digits > 0) digits--;
            else ans += s[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};