class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = -1;
        string temp = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                while(i<s.length() && s[i] >= '0' && s[i] <= '9'){
                    temp += s[i];
                    i++;
                }
                if(stoi(temp) > prev){
                    prev = stoi(temp);
                    temp = "";
                }
                else return false;
            }
        }
        return true;
    }
};