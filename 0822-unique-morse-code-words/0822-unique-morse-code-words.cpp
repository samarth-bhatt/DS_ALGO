class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>transformations;
        transformations = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string>unique;
        string temp;
        for(string i: words){
            temp = "";
            for(char j: i){
                temp += transformations[j-'a'];
            }
            unique.insert(temp);
        }
        return unique.size();
    }
};