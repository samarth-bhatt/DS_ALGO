class Solution {
public:
    vector<string> cellsInRange(string s) {
        int rows = s[4] - s[1];
        int cols = s[3] - s[0];
        // cout << rows << " " << cols << endl;
        rows++; cols++;
        vector<string>ans;
        string start;
        start = s.substr(0,2);
        for(int i=0; i<cols; i++){
            for(int j=0; j<rows; j++){
                ans.push_back(start);
                start[1]++;
            }
            start[0]++;
            start[1] -= (rows);
        }
        return ans;

    }
};