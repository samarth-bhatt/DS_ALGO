class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string temp;
        for(int i=0; i<=s.length(); i++){
            if(s[i] == ' ' || i == s.length()){
                reverse(begin(temp), end(temp));
                ans += temp;
                ans += ' ';
                temp = "";
            }
            else temp += s[i];
        }
        return ans.substr(0,ans.length()-1);
    }
};