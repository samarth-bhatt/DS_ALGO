//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
typedef long long ll;
class Solution{
    public:
    ll helper(int i, int j, int arr[], vector<vector<ll>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        ll pickStart = arr[i] + min(helper(i+2, j, arr, dp), helper(i+1, j-1, arr, dp));
        ll pickEnd = arr[j] + min(helper(i+1, j-1, arr, dp), helper(i, j-2, arr, dp));
        return dp[i][j] = max(pickStart, pickEnd);
    }
    long long maximumAmount(int arr[], int n){
        vector<vector<ll>>dp(n, vector<ll>(n, -1));
        return helper(0, n-1, arr, dp);
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
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends