class Solution {
public:
    string truncateSentence(string s, int k) {
        int spaceCnt = 0;
        string sentence = "";
        // while(spaceCnt != k-1){
            for(auto &i: s){
                if(i == ' '){
                    spaceCnt++;
                    if(spaceCnt == k) return sentence;
                    sentence += ' ';
                } else{
                    sentence += i;
                }
            }
        // }
        return sentence;
    }
};