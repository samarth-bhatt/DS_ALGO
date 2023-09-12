class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> freq; // for storing frequency of characters
        unordered_map<int, int> freqCnt; // for storing freq of freq
        for(char &i : s){
            freq[i]++;
        }

        int deletions = 0;
        for(auto &[a, b] : freq){ // a represents character, b represents count
            while(freqCnt[b] > 0){
                // If there's already a character with the same frequency, decrement the frequency
                b--;
                deletions++;
            }
            if(b > 0)freqCnt[b]++;
        }
        return deletions;
    }
};