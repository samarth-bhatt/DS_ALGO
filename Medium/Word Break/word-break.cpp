//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    bool helper(int ind, string A, unordered_set<string> &words, vector<int> &dp){
        if(ind >= A.length()) return dp[ind] = true;
        if(words.find(A) != words.end()) return dp[ind] = true;
        if(dp[ind] != -1) return dp[ind];
        for(int len = 1; len <= A.length()-ind; len++){
            string temp = A.substr(ind, len);
            if(words.find(temp) != words.end() && helper(ind+len, A, words, dp)) return dp[ind] = true;
        }
        return dp[ind] = false;
    }
    int wordBreak(string A, vector<string> &B) {
        unordered_set<string>words;
        for(auto &i: B) words.insert(i);
        vector<int>dp(A.size() + 1, -1);
        return helper(0, A, words, dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends