//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int flips) {
        // Simple Two Pointer Approach
        // initializing left and right pointers to marflips the starting
        // and the ending of the window containg flips 0's
        // then we'll store the answer for the current window and 
        // move on to the next window to accordingly update our answer to a better one
        int left = 0;
        int right = 0;
        int maxLen = INT_MIN;
        while(right < n){
            if(nums[right] == 0) flips--;
            while(flips <0){
                if(nums[left] == 0) flips++;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends