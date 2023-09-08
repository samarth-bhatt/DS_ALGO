class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>a;
        for (int i=0; i<numRows; i++){
            vector<int>v(i+1,1);
                for(int j=1;j<i;j++){
                v[j]=a[i-1][j-1]+a[i-1][j];
                }
            a.push_back(v);
            }
        return a;
    }
};