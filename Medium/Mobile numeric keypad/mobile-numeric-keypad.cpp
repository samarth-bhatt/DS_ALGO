//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{

	public:
    long long helper(int row, int col, int N, vector<vector<int>>phone, vector<vector<long long>> &dp){
        // if(row < 0 || col < 0 || row >= 4 || col >= 3) return 0;
        if(N == 1) return 1;
        if(dp[phone[row][col]][N] != -1) return dp[phone[row][col]][N];
        long long curr = 0, top = 0, left = 0, right = 0, bottom = 0;
        curr = helper(row, col, N-1, phone, dp);
        
        // Checking top cell
        if (row - 1 >= 0 && phone[row - 1][col] != -1) top = helper(row-1, col, N-1, phone, dp);
        // Check left cell
        if (col - 1 >= 0 && phone[row][col - 1] != -1) left = helper(row, col-1, N-1, phone, dp);
        // Check right cell
        if (col + 1 < 3 && phone[row][col + 1] != -1) right = helper(row, col+1, N-1, phone, dp);
        // Check bottom cell
        if (row + 1 < 4 && phone[row + 1][col] != -1) bottom = helper(row+1, col, N-1, phone, dp);
        return dp[phone[row][col]][N] = curr + top + left + right + bottom;
    }
	
	long long getCount(int N)
	{
		vector<vector<int>>phone = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
		vector<vector<long long>>dp(10, vector<long long>(N+1, -1)); // {numbers from 0-9, length}
		long long ans = 0;
		for(int i=0; i<4; i++){
		    for(int j=0; j<3; j++){
		        if(phone[i][j] != -1){
		            ans += helper(i, j, N, phone, dp);
		        }
		    }
		}
		return ans;
	}


};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends