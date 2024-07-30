class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //creating graph
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto i: times){
            adj[i[0]].push_back({i[1], i[2]});
        }
        queue<pair<int, pair<int,int>>>q;
        vector<int>time(n+1, 1e8);
        time[k] = 0;
        q.push({0, {k, 0}});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int mint = curr.first;
            int node = curr.second.first;
            int t = curr.second.second;
            for(auto i: adj[node]){
                if(t+i.second < time[i.first]){
                    time[i.first] = t + i.second;
                    q.push({t + i.second, {i.first, t + i.second}});
                }
            }
        }
        int maxTime = 0;
        for(int i=1; i<=n; i++){
            if(time[i] == 1e8) return -1;
            maxTime = max(maxTime, time[i]);
        }
        return maxTime;
    }
};