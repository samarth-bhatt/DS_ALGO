class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        unordered_map<char, int>elePos;
        int maxLen = 0;
        int left = 0;
        // elePos[left] = left;
        for(int right=0; right<s.length(); right++){
            if(elePos.find(s[right]) != elePos.end()){
                left = max(left, 1 + elePos[s[right]]); // if present then update
            }
            elePos[s[right]] = right; // insert
            maxLen = max(maxLen,right - left + 1);
        }
        return maxLen;
    }
};