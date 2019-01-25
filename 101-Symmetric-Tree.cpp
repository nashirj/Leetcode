/*
101. Symmetric Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/

/*
RECURSIVE SOLUTION
traverse left subtree, reverse traverse right subtree; current node must be same at every step
any traversal will work fine for this
        
O(n) time, have to check every node, O(n) space since tree can be linear, and so will need n recursive calls
*/

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode* left, TreeNode* right){
        if (!left && !right)
            return true;
        if (!left || !right || (left->val != right->val))
            return false;
        
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};





/*
ITERATIVE SOLUTION

O(n) time, have to check every node, O(n) space since every node is added to either leftTree or rightTree
*/

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        
        //iterative solution
        //use a queue for left subtree and a queue right subtree
        //check that they are same at every point
        
        queue<TreeNode*> leftTree, rightTree;
        
        if (root->left)
            leftTree.push(root->left);
        if (root->right)
            rightTree.push(root->right);
        
        while(!(leftTree.empty()) && !(rightTree.empty())){
            TreeNode* left = leftTree.front();
            leftTree.pop();
            TreeNode* right = rightTree.front();
            rightTree.pop();
            
            if (left->val != right->val)
                return false;
            
            //need to sync up left->left and right->right
            //need to sync up left->right and right->left
            if (left->left && right->right){
                leftTree.push(left->left);
                rightTree.push(right->right);
            }
            else{
                if (left->left || right->right)
                    return false;
            }
            
            if (left->right && right->left){
                leftTree.push(left->right);
                rightTree.push(right->left);
            }
            else{
                if (left->right || right->left)
                    return false;
            }
        }
        
        if (!(leftTree.empty()) || !(rightTree.empty()))
            return false;
        
        return true;
        
    }
};