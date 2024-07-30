class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n, vector<int>(n, 1e8));
        for(auto i: edges){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) dist[i][j] = 0;
            }
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k] == 1e8 || dist[k][j] == 1e8)
						continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int city = -1;
        int maxCnt = INT_MAX;
        for(int i=0; i<n; i++){
            int cnt=0; 
            for(int j=0; j<n; j++){
                if(dist[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= maxCnt){
                city = i;
                maxCnt = cnt;
            }
        }
        return city;
    }
};