class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Sliding Window + Deque based approach
        deque<int>dq;
        vector<int>maxwnd; // window which will contain the maximum elements in every window of size k
        int n = nums.size();
        // processing the first k elements
        for(int i=0;i<k;i++){
            // popping out the smaller elements from the back, since, they lose the potential to become the maximum element in this window, since current element will be enetered in this window which holds a better chance than those previous elements
            while(!dq.empty() && nums[i]>nums[dq.back()]){
                dq.pop_back();
            }
            // every elements will be enetered once in the window, giving it a potential chance to become the maximum in the current window
            // We push the index, instead of directly pushing the element
            dq.push_back(i);
        }
        for(int i=k;i<n;i++){
            // maximum element is in the front of th window, pushing it into ans
            maxwnd.push_back(nums[dq.front()]);
            // popping the elements from front, which goes out of window
            while(!dq.empty() && dq.front()<=(i-k)){
                dq.pop_front();
            }
            // popping the smaller elements from the back
            while(!dq.empty() && nums[i]>nums[dq.back()]){
                dq.pop_back();
            }
            // pushing the index of the currently processed element, to give it a potential chance of becoming a maximum in this window
            dq.push_back(i);
        }
        // at the end, processing the maximum for the last window
        maxwnd.push_back(nums[dq.front()]);
        return maxwnd;
    }
};