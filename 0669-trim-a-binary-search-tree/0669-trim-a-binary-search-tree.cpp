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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL) return NULL;
        // if root's value lies in the range
        // then simply, calling recursion for its children and assigning root's left and root's right as what being returned  by the recurive calls
        if(root->val >= low && root->val <= high){
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }
        // if the value of root is lesser than low, then all values on the left of root will also be smaller, hence, passing the right subtree in the recursive call
        else if(root->val < low) return trimBST(root->right, low, high);
        // if the value of root is greater than high, then all values on the right of root will also be greater, hence, passing the left subtree in the recursive call
        else return trimBST(root->left, low, high);
        return root;
    }
};