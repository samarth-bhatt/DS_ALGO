class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for(string &i: patterns) if(word.find(i) != string::npos) ans++;
        return ans;
    }
};