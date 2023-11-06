class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, int>wordList;
        for(string &i: words) wordList[i]++;
        int cnt = 0;
        string revWord;
        for(string &i: words){
            revWord = i;
            reverse(revWord.begin(), revWord.end());
            wordList[i]--;
            if(wordList[i] == 0) wordList.erase(i);
            if(wordList.find(revWord) != wordList.end()){
                cnt++;
                wordList[revWord]--;
                if(wordList[revWord] == 0) wordList.erase(revWord);
            }
        }
        return cnt;
    }
};