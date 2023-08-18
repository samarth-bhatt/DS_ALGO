class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        vector<pair<int, int>>beamsInRow(n);
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<m; j++){
                if(bank[i][j] == '1') count++;
            }
            beamsInRow[i] = {i, count};
        }
        int totalBeams = 0;
        for(int i=0; i<n; i++){
            if(beamsInRow[i].second == 0) continue;
            int curr = beamsInRow[i].second;
            int next = 0;
            for(int j=i+1; j<n; j++){
                if(j<n && beamsInRow[j].second != 0){
                    next = beamsInRow[j].second;
                    break;
                }
            }
            totalBeams += curr * next;
        }
        return totalBeams;
    }
};