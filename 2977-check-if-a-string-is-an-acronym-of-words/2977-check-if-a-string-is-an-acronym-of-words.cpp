class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string ans = "";
        for(auto i: words) ans += i[0];
        return ans == s;
    }
};