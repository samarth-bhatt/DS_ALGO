#include <bits/stdc++.h>
class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char>vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');
        vowels.insert('A');
        vowels.insert('E');
        vowels.insert('I');
        vowels.insert('O');
        vowels.insert('U');
        vector<pair<char, int>>vow;
        vector<int>pos;
        for(int i=0; i<s.length(); i++){
            if(vowels.find(s[i]) != vowels.end()){
                vow.push_back({s[i], i});
                pos.push_back(i);
            }
        }
        sort(vow.begin(), vow.end());
        int j = 0;
        for(auto i: pos){
            s[i] = vow[j++].first;
        }
        return s;
    }
};