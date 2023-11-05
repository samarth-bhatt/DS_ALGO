class Solution {
public:
    string removeSideMostParentheses(string &str){
        return str.substr(1,str.length()-2);
    }
    string removeOuterParentheses(string s) {
        string ans;
        string temp;
        int opening = 0, closing = 0;
        for(char &i: s){
            if(i == '('){
                temp += i;
                opening++;
            } else{
                closing++;
                temp += i;
                if(opening == closing){
                    ans += removeSideMostParentheses(temp);
                    temp = "";
                    opening = 0;
                    closing = 0;
                }
            }
        }
        return ans;
    }
};