class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>>ans;
        vector<pair<int, int>>info; // {person, group size}
        for(int person=0; person<n; person++){
            info.push_back({groupSizes[person], person});
        }
        sort(begin(info), end(info));
        int i = 0;
        while(i < n){
            int size = info[i].first;
            vector<int>temp(size);
            for(int j=0; j<size; j++){
                temp[j] = info[i].second;
                i++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};