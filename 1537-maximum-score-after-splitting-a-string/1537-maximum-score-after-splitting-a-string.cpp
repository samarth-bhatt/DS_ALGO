class Solution {
public:
    int maxScore(string s) {
        int rightOnes = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '1') rightOnes ++;
        }
        int maxScore = INT_MIN;
        int leftZeros = 0;
        for(int i=0; i<s.length()-1; i++){
            if(s[i] == '0') leftZeros++;
            else rightOnes--;
            maxScore = max(maxScore, leftZeros + rightOnes);
        }
        return maxScore;
    }
};