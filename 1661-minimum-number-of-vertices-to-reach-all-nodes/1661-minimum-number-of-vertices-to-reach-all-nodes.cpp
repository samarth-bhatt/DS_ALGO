class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>incoming(n);
        vector<int>ans;
        for(auto i: edges){
            incoming[i[1]]++;
        }
        for(int i=0; i<n; i++){
            if(incoming[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};