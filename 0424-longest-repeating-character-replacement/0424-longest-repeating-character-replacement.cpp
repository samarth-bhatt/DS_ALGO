class Solution {
public:
    int characterReplacement(string s, int k) {
        // k replacements is similar to having k distinct elements in a window
        int n = s.size();
        int left  = 0;
        int right = 0;
        int ans = 0;
        unordered_map<char, int>distinct;
        int maxFreq = 0;   // *IMP* : We need to keep the track of the most frequent element, since, if we want to convert the other characters to a single character, then we'l try to convert the other characters to the most frequent one, leaving th emost frequent one undisturberd, this will minimize the conversions we need to perform
        while(right < n){
            distinct[s[right]]++;
            maxFreq = max(maxFreq, distinct[s[right]]);
            // Checking if we can make the substring valid by performing 'k' replacements
            while(right - left + 1 - maxFreq> k){
                // In current window, if the characters that needs to be converted, are more than the available conversions i.e. k
                // then it is not possible to perform the conversion, hence in that case, we shrink the window
                distinct[s[left]]--;
                left++;
            }    
            ans = max(ans, right - left + 1);
            right++;       
        }
        return ans;
    }
};