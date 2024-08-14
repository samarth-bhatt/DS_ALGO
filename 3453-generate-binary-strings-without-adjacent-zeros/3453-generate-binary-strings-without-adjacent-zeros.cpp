class Solution {
public:
    void helper(string str, int ind, vector<string> &ans){
        if(ind >= str.length()) {ans.push_back(str); return;}
        str[ind] = '0';
        helper(str, ind+2, ans); // converted to zero, so moving by 2 so that adjacent zeros not occur
        str[ind] = '1'; // backtracking
        helper(str, ind+1, ans); // leaving 1 as it is
    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        string str(n, '1');
        helper(str, 0, ans);
        return ans;
    }
};