//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int AlternatingaMaxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;
        int increasing = 1;   // max inc subsequence length possible at an index i
        int decreasing = 1;   // max dec subsequence length possible at an index i
        for(int i=1; i<n; i++){
            if(nums[i] - nums[i-1] > 0){        // increasing
                increasing = 1 + decreasing;
                // Increasing sequence formed by adding current element to the longest decreasing subsequence.                
            }
            else if(nums[i] - nums[i-1] < 0){   // decreasing
                decreasing = 1 + increasing;
                // Decreasing sequence formed by adding current element to the longest increasing subsequence.
            }
            // If the current element is equal to the previous element, it doesn't contribute to either increasing or decreasing subsequence.
        }
        maxLen = max(maxLen, max(increasing, decreasing));
        return maxLen;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends