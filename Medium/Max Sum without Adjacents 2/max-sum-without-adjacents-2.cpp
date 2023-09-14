//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
//   int helper(vector<int> &a, int ind, vector<int> &dp){
//       if(ind < 0) return 0;
//       if(ind == 0) return a[0];
//       if(ind == 1) return a[0] + a[1];
//       if(dp[ind] != -1) return dp[ind];
//       return dp[ind] = max({helper(a, ind-1, dp), a[ind] + helper(a, ind-2, dp), a[ind] + a[ind-1] + helper(a, ind-3, dp)});
//   }
//   int findMaxSum(vector<int>& a){
//       // three cases arises,
//     //   (i) not pick and move to ind-1
//     //   (ii) pick and move to ind-2
//     //   (iii) pick and move to ind-3
//     int n = a.size();
//     vector<int>dp(n, -1);
//     return helper(a, n-1, dp);
//   }

    int findMaxSum(vector<int>& a) {
        int n = a.size();
        if (n == 0) return 0;
        if (n == 1) return a[0];
        if (n == 2) return a[0] + a[1];

        vector<int> dp(n);
        dp[0] = a[0];
        dp[1] = a[0] + a[1];
        dp[2] = max({a[0] + a[1], a[0] + a[2], a[1] + a[2]});

        for(int i = 3; i < n; i++){
            dp[i] = max({dp[i - 1], dp[i - 2] + a[i], dp[i - 3] + a[i] + a[i-1]});
        }

        return dp[n - 1];
    }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends