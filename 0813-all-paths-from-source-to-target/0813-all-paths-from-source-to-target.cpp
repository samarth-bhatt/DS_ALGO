class Solution {
public:
    void helper(vector<vector<int>> &graph, int node, int dst, vector<vector<int>>&ans, vector<int>&path){
        if(node == dst){
            ans.push_back(path);
            return;
        }
        for(auto adjNode: graph[node]){
            path.push_back(adjNode);
            helper(graph, adjNode, dst, ans, path);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>ans;
        vector<int>path;
        path.push_back(0);
        helper(graph, 0, n-1, ans, path);
        return ans;
    }
};