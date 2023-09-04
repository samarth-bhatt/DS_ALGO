//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i == 0) || (i == n-1) || (j == 0) || (j == m-1)){
                    if(mat[i][j] == 'O'){
                        vis[i][j] = true;
                        q.push({i,j});
                    }
                }
            }
        }
        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nRow = row + dr[i];
                int nCol = col + dc[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m &&
                !vis[nRow][nCol] && mat[nRow][nCol] == 'O'){
                    vis[nRow][nCol] = true;
                    q.push({nRow, nCol});
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]) mat[i][j] = 'O';
                else mat[i][j] = 'X';
            }
        }
        return mat;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends