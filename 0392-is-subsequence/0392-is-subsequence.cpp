class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m > n) return false;
        int i=0, j=0;
        while(i<m && j<n){
            if(i == m) return true;
            if(j == n) return false;
            if(s[i] == t[j]){
                i++;
                j++;
            } else{
                j++;
            }
        }
        return i == m;
    }
};