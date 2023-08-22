//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool countEven(int row, int col, vector<vector<int>> &matrix){
        int surrounding = 0;
        int dr[] = {+1, 0, -1, 0, +1, -1, +1, -1};
        int dc[] = {0, +1, 0, -1, -1, +1, +1, -1};
        for(int i=0; i<8; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow>=0 && ncol>=0 && nrow<matrix.size() && ncol<matrix[0].size() && matrix[nrow][ncol] == 0) surrounding++;
        }
        return (surrounding >0 && surrounding % 2 == 0);
    }
    int Count(vector<vector<int> >& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 1){
                    if(countEven(i, j, matrix)) ans++;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends