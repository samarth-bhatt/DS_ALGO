class Solution {
private:
    const int MOD = 1e9 + 7;
    long countPossibilities(long n){
        if(n%2) return (((n+1)/2)*n) % MOD;
        else return ((n/2)*(n+1)) % MOD;
    }
public:
    
    int countHomogenous(string s) {
        long ans = 0;
        int cnt = 1;
        char currLetter = s[0];
        for(int i=1; i<s.length(); i++){
            if(s[i] == currLetter) cnt++;
            else{
                ans = (ans + countPossibilities(cnt)) % MOD;
                currLetter = s[i];
                cnt = 1;
            }
        }
        ans += countPossibilities(cnt);
        return ans;
    }
};