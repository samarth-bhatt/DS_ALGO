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
    void helper(TreeNode *root, int &sum, TreeNode *parent, TreeNode *grandParent){
        if(root == NULL) return;
        if(grandParent != NULL && grandParent->val % 2 == 0) sum += root->val;
        helper(root->left, sum, root, parent);
        helper(root->right, sum, root, parent);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        helper(root, sum, NULL, NULL);
        return sum;
    }
};