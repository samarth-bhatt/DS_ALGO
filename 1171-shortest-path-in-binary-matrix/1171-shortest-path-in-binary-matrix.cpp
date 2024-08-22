class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] == 1) return -1;
        if((grid[0][0] == 0) && (m == 1) && (n == 1)) return 1;
        vector<vector<bool>>vis(m, vector<bool>(n, 0));
        queue<pair<pair<int,int>, int>>q;
        q.push({{0,0}, 1});
        vis[0][0] = 1;
        
        while(!q.empty()){
            pair<int,int>curr = q.front().first;
            int curr_x = curr.first;
            int curr_y = curr.second;
            int currLen = q.front().second;
            int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
            int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
            for(int i=0; i<8; i++){
                int nrow = curr_x + dr[i];
                int ncol = curr_y + dc[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == 0 && !vis[nrow][ncol]){
                    q.push({{nrow, ncol}, currLen+1});
                    vis[nrow][ncol] = 1;
                    if(nrow == m-1 && ncol == n-1) return currLen+1;
                }                
            }
            q.pop();
        }
        return -1;
    }
};