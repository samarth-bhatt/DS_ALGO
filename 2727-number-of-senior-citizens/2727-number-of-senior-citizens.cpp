#include <bits/stdc++.h>
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(string &s: details){
            string age;
            age = s.substr(11,2);
            if(stoi(age) > 60) count++;
        }
        return count;
    }
};