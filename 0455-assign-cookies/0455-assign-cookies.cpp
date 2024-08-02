class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size();
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        int child_ptr = 0, cookie_ptr = 0;
        int max_feed = 0;
        while(child_ptr<n && cookie_ptr<m){
            if(g[child_ptr] <= s[cookie_ptr]){
                max_feed++;
                child_ptr++;
            }
            cookie_ptr++;
        }
        return max_feed;
    }
};