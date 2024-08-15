class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>>ans(n, vector<int>(m));
        for(int i=0; i<min(n,m); i++){
            ans[i][i] = min(rowSum[i], colSum[i]);
            rowSum[i] -= ans[i][i];
            colSum[i] -= ans[i][i];
        }
        for(int i=0; i<n; i++){
            if(rowSum[i] == 0) continue;
            for(int j=0; j<m; j++){
                if(colSum[j] != 0){
                    ans[i][j] = min(colSum[j], rowSum[i]);
                    colSum[j] -= ans[i][j];
                    rowSum[i] -= ans[i][j];
                }
                if(rowSum[i] == 0) break;
            }
        }
        return ans;
    }
};