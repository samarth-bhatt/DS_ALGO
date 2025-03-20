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
    bool isLeaf(TreeNode *node){
        return (!node->left && !node->right);
    }
    void helper(TreeNode *root, int &sum, bool leftCall){
        if(root == NULL) return;
        if(leftCall && isLeaf(root))
            sum += root->val;
        helper(root->left, sum, true);
        helper(root->right, sum, false);  
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        bool leftCall = false;
        helper(root, sum , leftCall);
        return sum;
    }
};