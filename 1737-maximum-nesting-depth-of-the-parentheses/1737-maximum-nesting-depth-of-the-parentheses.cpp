class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int ans = 0;
        for(char& i: s){
            if(i == '('){
                st.push('(');
                ans = max(ans, (int)st.size());
            } else if(i == ')') st.pop(); 
        }
        return ans;
    }
};