class Solution {
public:
    int minOperations(int n) {
        // 1 3 5 7 9 11
        int ans = 0;
        if(n%2){
            int median_ele = (n-1)/2;
            int median = 2*(median_ele) + 1;
            for(int i=0; i<median_ele; i++){
                ans += (median - (2*i + 1));
            }
        } else{
            int me1 = n/2 - 1;
            int me2 = n/2;
            int median = ((2*me1 + 1) + (2*me2 + 1))/2;
            for(int i=0; i<=me1; i++){
                ans += (median - (2*i + 1));
            }
        }
        return ans;
    }
};