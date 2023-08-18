class Solution {
public:
    bool isConnected(int a, int b, unordered_map<int, int> &mp){
        return mp.count(a*1000 + b) > 0;
    }
    
    int count(vector<vector<int>> &adj, int node){
        return adj[node].size();
    }
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads){
        vector<vector<int>> adj(n);
        unordered_map<int, int> mp;
        
        for(auto i: roads){
            int a = i[0], b = i[1];
            mp[a*1000 + b] = 1; // Storing hash of the pair (a, b)
            mp[b*1000 + a] = 1; // Storing hash of the pair (b, a)
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int curr = count(adj, i) + count(adj, j);
                if(isConnected(i, j, mp)) curr--;
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};




// ROUGH

// class Solution {
// public:
//     bool isConnected(int a, int b, unordered_map<int, int> &mp){
//         return mp.count({a, b}) > 0;
//     }
//     int count(vector<vector<int>> &adj, pair<int, int> &connection){
//         unordered_set<int>st;
//         for(auto i: adj[connection.first]) st.insert(i);
//         for(auto i: adj[connection.second]) st.insert(i);
//         return st.size();
//     }
//     int maximalNetworkRank(int n, vector<vector<int>>& roads) {
//         vector<vector<int>>adj(n);
//         map<pair<int, int>>mp;
//         for(auto i: roads){
//             mp.insert({i[0], i[1], 1});
//             // mp.insert({i[1], i[0]});
//         }
//         // creating the graph
//         for(auto i: roads){
//             adj[i[0]].push_back(i[1]);
//             adj[i[1]].push_back(i[0]);
//         }
//         int ans = 0;
//         int curr = 0;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 pair<int, int> connection = {i, j};
//                 curr = count(adj, connection);
//                 if(isConnected(i, j, mp) || isConnected(j, i, mp)) curr--;
//                 ans = max(ans, curr);
//             }
//         }
//         return ans;
//     }
// };