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
    pair<int, int> sumAndCount(TreeNode* root, int &ans){
        if(root == NULL) return {0, 0};
        pair<int, int> left = sumAndCount(root->left, ans);
        pair<int, int> right = sumAndCount(root->right, ans);
        int sum = left.first + right.first + root->val;
        int cnt = left.second + right.second + 1;
        if(sum/cnt == root->val) ans++;
        return {sum, cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        sumAndCount(root, ans);
        return ans;
    }
};