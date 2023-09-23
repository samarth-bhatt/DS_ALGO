class Solution {
public:
    bool difference(string &a, string &b){
        if(a.length() != b.length() + 1) return false;
        int la = 0, lb = 0;
        while(la < a.size()){
            if(lb < b.size() && a[la] == b[lb]){
                la ++;
                lb ++;
            }
            else la ++;
        }
        return (la == a.size() && lb == b.size());
    }
    static bool lengthComp(string &a, string &b){
        return a.length() < b.length();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        //first we have to sort the words array according to the length of strings
        sort(words.begin(), words.end(), lengthComp);
        vector<int>dp(n, 1);
        int ans = INT_MIN;
        for(int ind=0; ind<n; ind++){
            for(int prev=0; prev<ind; prev++){
                if(difference(words[ind], words[prev]) && 1 + dp[prev] > dp[ind]){
                    dp[ind] = 1 + dp[prev];
                }
            }
            ans = max(ans, dp[ind]);
        }
        return ans;
    }
};