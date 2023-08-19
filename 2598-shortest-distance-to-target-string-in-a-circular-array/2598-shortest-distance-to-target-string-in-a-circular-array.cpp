class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = words.size();
        int i = startIndex;
        int cnt = 0;
        bool wordPresent = false;
        do{
            if(words[i] == target){
                wordPresent = true;
                ans = min(ans, min(cnt, (n-cnt)));
                if(ans == 0) return ans;
            }
            cnt++;
            i = (i+1) % n;
        }while(i != startIndex);
        return wordPresent ? ans : -1;
    }
};