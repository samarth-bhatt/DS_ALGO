class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>charsAllowed;
        for(char i: allowed) charsAllowed.insert(i);
        int consistent = 0;
        bool mismatch;
        for(string i: words){
            mismatch = false;
            for(char j: i){
                if(charsAllowed.find(j) == charsAllowed.end()){
                    mismatch = true;
                    break;
                }
            }
            if(!mismatch) consistent++;
        }
        return consistent;
    }
};