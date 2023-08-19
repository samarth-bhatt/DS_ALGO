class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>maxInRow(n), maxInCol(n);
        for(int i=0; i<n; i++){
            int maxi = 0;
            int maxj = 0;
            for(int j=0; j<n; j++){
                maxi = max(maxi, grid[i][j]);
                maxj = max(maxj, grid[j][i]);
            }
            maxInRow[i] = maxi;
            maxInCol[i] = maxj;
        }
        int ans = 0, curr = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                curr = min(maxInRow[i], maxInCol[j]);
                ans += (curr - grid[i][j]);
            }
        }
        return ans;
    }
};