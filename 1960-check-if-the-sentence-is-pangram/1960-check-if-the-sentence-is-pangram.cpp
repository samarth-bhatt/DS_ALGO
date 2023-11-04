class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char>alphabets;
        for(char &i: sentence){
            alphabets.insert(i);
            if(alphabets.size() == 26) return true;
        }
        return false;
    }
};