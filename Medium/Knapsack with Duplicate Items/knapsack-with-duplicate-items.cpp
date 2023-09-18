//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int ind, int cap, int val[], int wt[], vector<vector<int>> &dp){
        if(ind < 0 || cap <= 0) return 0;
        if(dp[ind][cap] != -1) return dp[ind][cap];
        // pick
        int pick = 0;
        if(cap >= wt[ind]) pick = val[ind] + helper(ind, cap - wt[ind], val, wt, dp);
        int notPick = helper(ind-1, cap, val, wt, dp);
        return dp[ind][cap] = max(pick, notPick);
    }
    
    int knapSack(int N, int W, int val[], int wt[]){
        vector<vector<int>>dp(N, vector<int>(W+1, -1));
        return helper(N-1, W, val, wt, dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends