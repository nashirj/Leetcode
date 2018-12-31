/*
98. Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:

Input:
    2
   / \
  1   3
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
*/

/*
APPROACH 2
O(n) time, O(n) space (for each recursive call)
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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;
        
        return isValidBST(root, nullptr, nullptr);
    }
    
    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max){
        if (root == nullptr)
            return true;
        
        if ((min && (root->val <= min->val)) || (max && (root->val >= max->val))){
            return false;
        }
        
        bool left = true, right = true;
        
        //if you go right, update min, values can't be less than root
        if (root->left)
            left = isValidBST(root->left, min, root);
        //if you go left, update max, values can't be greater than root
        if (root->right)
            right = isValidBST(root->right, root, max);
        
        return (left && right);
    }
};




/*
APPROACH 1
not sure about time/space complexity
*/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;
        
        bool left, right, validLeftTree, validRightTree;
        
        if(root->left)
            left = isLess(root->left, root->val);
        else
            left = true;
        
        if(root->right)
            right = isGreater(root->right, root->val);
        else
            right = true;
        
        if(left && right){
            if(root->left)
                validLeftTree = isValidBST(root->left);
            else
                validLeftTree = true;
        
            if(root->right)
                validRightTree = isValidBST(root->right);
            else
                validRightTree = true;
        }
        else
            return false;
        return (validLeftTree && validRightTree);
    }
    
    public: bool isLess(TreeNode* root, int val){
        if (root->left == nullptr && root->right == nullptr)
            return root->val < val;
        bool left, right;
        if(root->val < val){
            if(root->left)
                left = isLess(root->left, val);
            else
                left = true;
            if(root->right)
                right = isLess(root->right, val);
            else
                right = true;
        }
        else
            return false;
        
        return (left && right);
    }
    public: bool isGreater(TreeNode* root, int val){
        if (root->left == nullptr && root->right == nullptr)
            return root->val > val;
        bool left, right;
        if(root->val > val){
            if(root->left)
                left = isGreater(root->left, val);
            else
                left = true;
            if(root->right)
                right = isGreater(root->right, val);
            else
                right = true;
        }
        else
            return false;
        return (left && right);
    }
};