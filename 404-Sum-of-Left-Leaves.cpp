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
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeaves(root, false);
    }
    int sumOfLeftLeaves(TreeNode* root, bool left) {
        if (!root) {
            return 0;
        }
        
        if (!root->left && !root->right && left) {
            return root->val;
        }
        
        return sumOfLeftLeaves(root->right, false) + sumOfLeftLeaves(root->left, true);
    }
};