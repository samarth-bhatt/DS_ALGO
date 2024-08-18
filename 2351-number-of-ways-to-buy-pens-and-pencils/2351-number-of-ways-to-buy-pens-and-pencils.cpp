class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        // cost1 * x + cost2 * y = total
        // y = (total - cost1 * x) / cost2
        long long ans = 0;
        if(cost1 > cost2) swap(cost1, cost2);
        for(int i=0; i<=total/cost1; i++){
            // int j = ((total - cost1*i)/cost2)%2 ? 0 : (total - cost1*i)/cost2;
            int j = (total - cost1*i)/cost2;
            ans += j + 1;
        }
        return ans;
    }
};