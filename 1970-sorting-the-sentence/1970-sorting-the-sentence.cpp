class Solution {
public:
    string sortSentence(string s) {
        vector<pair<int, string>>ordering;
        string temp;
        for(int i=0; i<s.length(); i++){
            if(s[i] >= '1' && s[i] <= '9'){
                ordering.push_back({s[i] - '0', temp});
            } else if(s[i] == ' ') temp = "";
            else temp += s[i];
        }
        sort(begin(ordering), end(ordering));
        string ans;
        for(auto &i: ordering){
            ans += i.second;
            ans += ' ';
        }
        return ans.substr(0,ans.size()-1);
    }
};