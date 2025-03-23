/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        unordered_map<TreeNode*, TreeNode*>nodeParMap;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
                nodeParMap[curr->left] = curr;
            }
            if(curr->right){
                q.push(curr->right);
                nodeParMap[curr->right] = curr;
            }
        }
        unordered_set<TreeNode*>vis;
        q.push(target);
        vis.insert(target);
        while(!q.empty() && k--){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !(vis.count(curr->left) > 0)) {q.push(curr->left); vis.insert(curr->left);}
                if(curr->right && !(vis.count(curr->right) > 0)) {q.push(curr->right); vis.insert(curr->right);}
                if(nodeParMap.find(curr) != nodeParMap.end() && !(vis.count(nodeParMap[curr]) > 0)) {q.push(nodeParMap[curr]); vis.insert(nodeParMap[curr]);}
            }
        }
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};