class Solution {
public:
    int minPartitions(string n) {
        char curr = n[0];
        char ans = n[0];
        for(int i=1; i<n.length(); i++){
            curr = max(n[i], curr);
            ans = max(ans, curr);
        }
        return (int) (ans - '0');
    }
};