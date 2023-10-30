class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char>keyAlphaMap;
        char start = 'a';
        for(auto i: key){
            if('a' <= i && i <= 'z'){
                if(keyAlphaMap.find(i) != keyAlphaMap.end()) continue;
                keyAlphaMap[i] = start++;
            }
        }
        string ans;
        for(auto i: message){
            if('a' <= i && i <= 'z'){
                ans += keyAlphaMap[i];
            } else{
                ans += ' ';
            }
        }
        return ans;
    }
};