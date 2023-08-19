class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.length();
        int ans = 0; // ans stores the cnt
        for(int i=0; i<=n-k; i++){
            int temp = stoi(s.substr(i, k));
            if(temp!=0 && num % temp == 0) ans++;
        }
        return ans;
    }
};