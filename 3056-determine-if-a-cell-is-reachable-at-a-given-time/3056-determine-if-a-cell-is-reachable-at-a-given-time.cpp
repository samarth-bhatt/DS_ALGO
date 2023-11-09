class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy) return t != 1;
        int xDist = abs(sx-fx);
        int yDist = abs(sy-fy);
        return (xDist <= t && yDist <= t);
    }
};