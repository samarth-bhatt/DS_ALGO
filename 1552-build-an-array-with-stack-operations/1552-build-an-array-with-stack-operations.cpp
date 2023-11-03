class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        string pu = "Push", po = "Pop";
        vector<string>ans;
        int i = 0;
        for(int start=1; start<=n; start++){
            if(i == target.size()) break;
            if(target[i] == start){
                ans.push_back(pu);
                i++;
            } else{
                ans.push_back(pu);
                ans.push_back(po);
            }
        }
        return ans;
    }
};