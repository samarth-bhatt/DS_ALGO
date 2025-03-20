class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char>c1, c2, c3;
        string firstRow = "qwertyuiop";
        string secondRow = "asdfghjkl";
        string thirdRow = "zxcvbnm";
        vector<string>ans;
        for(const char &i: firstRow) c1.insert(i);
        for(const char &i: secondRow) c2.insert(i);
        for(const char &i: thirdRow) c3.insert(i);
        for(const string &word: words){
            if(word.length() == 1){
                ans.push_back(word);
                continue;
            }
            unordered_set<char> curr = c1;
            if(c1.contains(tolower(word[0]))) curr = c1;
            else if(c2.contains(tolower(word[0]))) curr = c2;
            else curr = c3;
            for(int i=1; i<word.length(); i++){
                if(!curr.contains(tolower(word[i]))) break;
                if(i == word.length()-1) ans.push_back(word);
            }
        }
        return ans;
    }
};