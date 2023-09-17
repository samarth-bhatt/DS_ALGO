//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int targetSum(int arr[], int ind, vector<vector<int>> &dp, int tar){
        if(tar == 0) return 1;
        if (ind < 0 || tar < 0) return false;
        if(dp[ind][tar] != -1) return dp[ind][tar];
        // pick
        int pick = 0;
        if(arr[ind] <= tar) pick = targetSum(arr, ind-1, dp, tar - arr[ind]);
        // not pick
        int notPick = targetSum(arr, ind-1, dp, tar);
        return dp[ind][tar] = pick || notPick;
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0; i<N; i++) sum += arr[i];
        if(sum%2) return false;
        vector<vector<int>>dp(N, vector<int>(sum/2 +1, -1));
        return targetSum(arr, N-1, dp, sum/2);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends