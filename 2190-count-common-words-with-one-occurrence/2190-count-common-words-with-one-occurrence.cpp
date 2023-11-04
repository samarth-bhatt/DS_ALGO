class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int cnt = 0;
        unordered_map<string, int>freq1, freq2;
        for(string &i: words1) freq1[i]++;
        for(string &i: words2) freq2[i]++;
        for(auto &p: freq1) if(p.second == 1 && freq2[p.first] == 1) cnt++;
        return cnt;
    }
};