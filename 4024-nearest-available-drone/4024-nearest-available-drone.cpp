class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int mini = INT_MAX;
        int index = -1;
        int counter = 0;
        for(auto &i: drones){
            int manhattenDist = abs(target[0] - i[0]) + abs(target[1] - i[1]);
            if(manhattenDist <= i[2]){
                if(manhattenDist < mini){
                    mini = manhattenDist;
                    index = counter;
                }
            }
            counter++;
        }
        return index;
    }
};