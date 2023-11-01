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
    void inorderTraversal(TreeNode* root, vector<int> &inorder){
        if(root == NULL) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>inorder;
        inorderTraversal(root, inorder);
        vector<int>modes;
        unordered_map<int, int>freq;
        for(int &i: inorder) freq[i]++;
        vector<pair<int, int>>keyCnt;
        for(auto &i: freq) keyCnt.push_back({i.second, i.first});
        sort(begin(keyCnt), end(keyCnt), [](pair<int, int>& a, pair<int, int>& b){
            return a.first > b.first;
        });
        int modalVal = keyCnt[0].first;
        for(auto &i: keyCnt){
            if(i.first == modalVal) modes.push_back(i.second);
            else break;
        } 
        return modes;
    }
};