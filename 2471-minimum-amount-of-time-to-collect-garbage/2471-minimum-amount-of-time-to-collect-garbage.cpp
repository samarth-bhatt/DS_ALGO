class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int total = 0;
        int paper_lastInd = 0, metal_lastInd = 0, glass_lastInd = 0;
        for(int i=0; i<garbage.size(); i++){
            int n = garbage[i].length();
            total += n;
            for(int j=0; j<n; j++){
                if(garbage[i][j] == 'P') paper_lastInd = i;
                if(garbage[i][j] == 'M') metal_lastInd = i;
                if(garbage[i][j] == 'G') glass_lastInd = i;
            }
        }
        for(int i=0; i<travel.size(); i++){
            if(i <= paper_lastInd-1) total += travel[i];
            if(i <= metal_lastInd-1) total += travel[i];
            if(i <= glass_lastInd-1) total += travel[i];
        }
        return total;
    }
};