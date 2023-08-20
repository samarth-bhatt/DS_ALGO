//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int kadane(vector<int> row){
        int n = row.size();
        int curr = row[0];
        int maxi = row[0];
        for(int i=1; i<n; i++){
            curr = max(curr + row[i], row[i]);
            maxi = max(maxi, curr);
        }
        return maxi;
    }
    
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int ans = INT_MIN;
        // for(int i=0; i<R; i++) temp[i] = M[i][0];
        // ans = max(ans, kadane(temp));
        for(int i=0; i<C; i++){
            vector<int>temp(R);
            for(int j=i; j<C; j++){
                for(int k=0; k<R; k++){
                    temp[k] += M[k][j];
                }
                int sum = kadane(temp);
                ans = max(sum, ans);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends