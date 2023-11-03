class Solution {
public:
    int countAsterisks(string s) {
        int cnt = 0;
        int asterixNo = 0;
        int i=0;
        bool canCnt = true;
        while(i<s.length()){
            if(canCnt){
                while(i<s.length() && s[i] != '|'){
                    if(s[i] == '*') cnt++;
                    i++;
                }
                canCnt = !canCnt;
                i++;
            } else{
                while(i<s.length() && s[i] != '|') i++;
                canCnt = !canCnt;
                i++;
            }
        }
        return cnt;
    }
};