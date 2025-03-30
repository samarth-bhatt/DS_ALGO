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
    void helper(TreeNode* root, int maxPar, int minPar, int &ans){
        if(root == NULL) return;
        ans = max(ans, abs(maxPar - root->val));
        ans = max(ans, abs(minPar - root->val));
        minPar = min(minPar, root->val);
        maxPar = max(maxPar, root->val);
        helper(root->left, maxPar, minPar, ans);
        helper(root->right, maxPar, minPar, ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        int maxPar = root->val;
        int minPar = root->val;
        helper(root, maxPar, minPar, ans);
        return ans;
    }
};