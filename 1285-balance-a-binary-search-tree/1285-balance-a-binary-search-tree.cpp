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
    TreeNode* createTree(vector<int> &inorder, int left, int right){
        if(left > right) return NULL;
        int mid = left + (right - left)/2;
        TreeNode *root = new TreeNode(inorder[mid]);
        root->left = createTree(inorder, left, mid-1);
        root->right = createTree(inorder, mid+1, right);
        return root;
    }
    void inorderTraversal(TreeNode *root, vector<int> &inorder){
        if(root == NULL) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        inorderTraversal(root, inorder);
        int low = 0;
        int high = inorder.size()-1;
        return createTree(inorder, 0, high);
    }
};