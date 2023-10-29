class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i=m-1; i>=0; i--){
            vector<int>temp;
            int rows = 0;
            int ini = i;
            while(rows < n && ini < m){
                temp.push_back(mat[rows][ini]);
                rows++;
                ini++;
            }
            sort(begin(temp), end(temp));
            int iter = 0;
            rows = 0;
            ini = i;
            while(rows < n && ini < m){
                mat[rows][ini] = temp[iter];
                rows++;
                ini++;
                iter++;
            }
        }

        for(int i=0; i<n; i++){
            vector<int>temp;
            int cols = 0;
            int ini = i;
            while(cols < m && ini < n){
                temp.push_back(mat[ini][cols]);
                cols++;
                ini++;
            }
            sort(begin(temp), end(temp));
            int iter = 0;
            cols = 0;
            ini = i;
            while(cols < m && ini < n){
                mat[ini][cols] = temp[iter];
                cols++;
                ini++;
                iter++;
            }
        }
        return mat;
    }
};