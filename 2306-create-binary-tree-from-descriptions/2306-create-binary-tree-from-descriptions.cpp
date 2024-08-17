/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, pair<TreeNode*, bool>>mapping; // parent val, {parent node, is_child}
        for(vector<int> &v: descriptions){
            TreeNode * par = NULL;
            TreeNode * child = NULL;
            if(mapping.find(v[0]) == mapping.end()){
                par = new TreeNode(v[0]);
                mapping[v[0]] = {par, false};                
            }
            else par = mapping[v[0]].first;
            if(mapping.find(v[1]) == mapping.end()){
                child = new TreeNode(v[1]);
                mapping[v[1]] = {child, false};
            }
            else child = mapping[v[1]].first;
            if(v[2] == 1) par->left = child;
            else par->right = child;
            mapping[v[1]].second = true;
        }
        TreeNode* root = NULL;
        for(const pair<int, pair<TreeNode*, int>> &i: mapping) if(i.second.second == false) {root = i.second.first; break;}
        return root;
    }
};