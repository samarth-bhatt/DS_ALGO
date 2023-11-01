class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int, int>freq;
        for(int i=0; i<num.length(); i++) freq[num[i] - '0']++;
        for(int i=0; i<num.length(); i++) if((num[i] - '0') != freq[i]) return false;
        return true;
    }
};