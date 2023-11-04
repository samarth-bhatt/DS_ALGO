class Solution {
public:
    int countPoints(string rings) {
        int n = rings.length()/2;   // total rods
        vector<vector<int>>rods(10, vector<int>(3));
        int count = 0;
        for(int i=0; i<2*n; i+=2){
            char col = rings[i];
            int rodNo = rings[i+1] - '0'; //0-based conversion
            if(col == 'R') rods[rodNo][0] = 1;
            else if(col == 'G') rods[rodNo][1] = 1;
            else rods[rodNo][2] = 1;
        }
        int colored = 0;
        for(auto i: rods){
            colored = 0;
            for(auto j: i) if(j == 1) colored++;
            if(colored == 3) count++;
        }
        return count;
    }
};