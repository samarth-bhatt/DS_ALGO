class Solution {
public:
    void countInRowAndCol(vector<vector<int>> &mat, vector<pair<int, int>> &rowInfo, vector<pair<int, int>> &colInfo){
        for(int i=0; i<mat.size(); i++){
            int zeroCnt = 0;
            int onesCnt = 0;
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 0) zeroCnt++;
                else onesCnt++;
            }
            rowInfo[i] = {zeroCnt, onesCnt};
        }
        for(int i=0; i<mat[0].size(); i++){
            int zeroCnt = 0;
            int onesCnt = 0;
            for(int j=0; j<mat.size(); j++){
                if(mat[j][i] == 0) zeroCnt++;
                else onesCnt++;
            }
            colInfo[i] = {zeroCnt, onesCnt};
        }
    }
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(); // no. of rows
        int m = grid[0].size(); // no. of cols
        vector<vector<int>>diff(n, vector<int>(m));
        vector<pair<int, int>>rowInfo(n);
        vector<pair<int, int>>colInfo(m);
        countInRowAndCol(grid, rowInfo, colInfo);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                diff[i][j] = rowInfo[i].second + colInfo[j].second - rowInfo[i].first - colInfo[j].first;
            }
        }
        return diff;
    }
};