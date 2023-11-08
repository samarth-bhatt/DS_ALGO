class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        // time = dist/speed;
        int n = dist.size();
        vector<double>time(n);
        for(int i=0; i<n; i++) time[i] = (double)dist[i]/speed[i];
        sort(begin(time), end(time));
        int count = 0;
        for(int i=0; i<n; i++) if(time[i] > i) count++; else break;
        return count;
    }
};