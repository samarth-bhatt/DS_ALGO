//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    const int MOD = 1e9 + 7;
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        // 2nCn/n+1
        vector<long long>dp(n+1);
        dp[0] = 1;
        
        // O(N^2) complexity
        for(int i=1; i<=n; i++){
            dp[i] = 0;
            for(int j=0; j<i; j++){
                dp[i] = (dp[i] + (dp[j] * dp[i-j-1]) % MOD) % MOD;
            }
        }
        
        // O(N) complexity
        // for(int i=1; i<=n; i++) dp[i] = (2 * (2 * i - 1) * dp[i - 1]) / (i + 1);
        return dp[n];
    }
};


//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends