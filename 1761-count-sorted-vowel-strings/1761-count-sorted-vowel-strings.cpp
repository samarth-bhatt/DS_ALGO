class Solution {
public:
    int countVowelStrings(int n) {
        // 1 1 1 1 1 = 5
        // 5 4 3 2 1 = 15
        // 15 10 6 3 1 = 35
        // 35 20 10 4 1
        vector<vector<int>>mat(n, vector<int>(5));
        int totSum = 0;
        for(int i=0; i<5; i++){mat[0][i] = 1; totSum += mat[0][i];}
        for(int i=1; i<n; i++){
            mat[i][0] = totSum;
            for(int j=1; j<5; j++){
                mat[i][j] = mat[i][j-1] - mat[i-1][j-1];
                totSum += mat[i][j];
            }
        }
        return totSum;
    }
};