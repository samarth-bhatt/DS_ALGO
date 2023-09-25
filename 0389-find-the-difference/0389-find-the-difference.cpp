class Solution {
public:
    char findTheDifference(string s, string t) {
       s.append(t);
       int sor = 0;
       for(int i=0;i<s.length();i++){
           sor = sor^s[i];
       } 
       return (sor-97+'a');
    }
};