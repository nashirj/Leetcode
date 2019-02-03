/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?

*/


//used only n extra space
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> vals;
        stack <TreeNode*> nodes;
        TreeNode *curr = root;
        while (curr || !nodes.empty()) {
            while (curr) {
                nodes.push(curr);
                curr = curr->left;
            }
            curr = nodes.top();
            nodes.pop();
            vals.push_back(curr->val);
            curr = curr->right;
        }
        return vals;
    }
};





//used 2n extra space, unordered_set and stack
/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vals;
        
        if (root == nullptr)
            return vals;
        
        stack<TreeNode*> nodes;
        unordered_set<TreeNode*> seen;
        
        nodes.push(root);
        seen.insert(root);
        
        while(!nodes.empty()){
            TreeNode* curr = nodes.top();
            
            while (curr->left){
                if (seen.find(curr->left) != seen.end())
                    break;
                curr = curr->left;
                nodes.push(curr);
                seen.insert(curr);
            }
            
            vals.push_back(curr->val);
            nodes.pop();
            
            if (curr->right){
                if (seen.find(curr->right) != seen.end())
                    break;
                curr = curr->right;
                nodes.push(curr);
                seen.insert(curr);
            }
            
        }
        
        return vals;
    }
};

*/