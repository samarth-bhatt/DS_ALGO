class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int>nodesConnected(n+1);
        for(auto &i: edges){
            nodesConnected[i[0]]++;
            nodesConnected[i[1]]++;
        }
        for(int i=1; i<=n; i++) if(nodesConnected[i] == n-1) return i;
        return -1;
    }
};