/**
1008. Construct Binary Search Tree from Preorder Traversal
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left
has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that
a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

 

Example 1:
Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Note: 
1 <= preorder.length <= 100
The values of preorder are distinct.
*/



// holy shit this is crazy simple
class Solution {
public:
    int i = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int bound=INT_MAX) {
        if (i == preorder.size() || preorder[i] > bound) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = bstFromPreorder(preorder, root->val);
        root->right = bstFromPreorder(preorder, bound);
        return root;
    }
};


class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstFromPreorder(preorder, 0, preorder.size()-1);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder, int left, int right) {
        if (left > right) {
            return nullptr;
        } else if (left == right) {
            return new TreeNode(preorder[left]);
        }
        TreeNode* root = new TreeNode(preorder[left]);
        if (preorder[left] > preorder[left+1]) {
            pair<int,int> left_window = getLeftSubtree(preorder, root->val, left+1, right);
            root->left = bstFromPreorder(preorder, left_window.first, left_window.second);
            root->right = bstFromPreorder(preorder, left_window.second+1, right);
        } else {
            root->right = bstFromPreorder(preorder, left+1, right);
        }
        
        return root;
    }
    
    pair<int,int> getLeftSubtree(vector<int>& preorder, int root_val, int left, int right) {
        // assume right < preorder.size(), max preorder.size()-1
        pair<int,int> window;
        window.first = left;
        for (int i = left+1; i <= right; i++) {
            if (preorder[i] > root_val) {
                window.second = i-1;
                return window;
            }
        }
        window.second = right; // if all the preorder are smaller
        return window;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */