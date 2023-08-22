//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int>> matrix, int n)
    {
        int totalSum = 0;
        int maxSum = INT_MIN;
        for(int i=0; i<n; i++){
            int currRowSum = 0;
            int currColSum = 0;
            for(int j=0; j<n; j++){
                currRowSum += matrix[i][j];
                currColSum += matrix[j][i];
            }
            maxSum = max(maxSum, max(currRowSum, currColSum));
            totalSum += currRowSum;
        }
        int ans = (maxSum * n) - totalSum;
        return ans;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends