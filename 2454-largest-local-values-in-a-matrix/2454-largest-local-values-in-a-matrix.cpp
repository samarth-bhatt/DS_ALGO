class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>ans(n-2, vector<int>(n-2));
        for(int i=0; i<n-2; i++){
            for(int j=0; j<n-2; j++){
                int start_row = i;
                int start_col = j;
                int maxi = INT_MIN;
                for(int l=start_row; l<start_row+3; l++){
                    for(int m=start_col; m<start_col+3; m++){
                        maxi = max(maxi, grid[l][m]);
                    }
                }
                ans[start_row][start_col] = maxi;
            }
        }
        return ans;
    }
};