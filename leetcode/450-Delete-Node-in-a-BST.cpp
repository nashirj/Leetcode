/*
450. Delete Node in a BST

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:
root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //if root is null, don't want to access and throw exception
        if (!root)
            return root;
        //assuming valid input, so don't worry about root->left/root->right being invalid
        //if root is greater than key, go left
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        //if root is less than key, go right
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        //if root is the value, delete it accordingly
        else { //(root->val == key)
            TreeNode* kill = root;
            //case 1: kill is a leaf
            if (!root->left && !root->right) {
                delete kill; //same as delete root
                root = nullptr; //just in case something else has a reference to this memory?
                return root;
            }
            //case 2: kill has one child. can't be zero or we'd enter block above
            else if (!root->left || !root->right) {
                if (root->left == nullptr) {
                    root = root->right;
                } else {
                    root = root->left;
                }
            }
            //case 3: kill has two children
            else {
                //need to find either (1) smallest node greater than root,
                //or (2) largest node smaller than root. either of these will
                //have at most one child. arbitrarily choose (2)
                TreeNode* prev = root;
                root = root->left;
                while (root->right) {
                    prev = root;
                    root = root->right;
                }
                //root now has no right child
                //same logic whether it (1) has left child or (2) is a leaf
                if (kill->left != root) {
                    prev->right = root->left;
                    root->left = kill->left;
                }
                root->right = kill->right;
            }
            //for cases (2) and (3), we will delete kill and return root
            delete kill;
            return root;
        }
        //if we made it here, we deleted the proper node, so return this subtree
        return root;
    }
};

/**
 * Solution without deleting, which has high overhead. can do this in competition, but deletion is necessary in real life
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //if root is null, don't want to access and throw exception
        if (!root)
            return root;
        //assuming valid input, so don't worry about root->left/root->right being invalid
        //if root is greater than key, go left
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        //if root is less than key, go right
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        //if root is the value, delete it accordingly
        else { //(root->val == key)
            TreeNode* kill = root;
            //case 1: kill is a leaf
            if (!root->left && !root->right) {
                // delete kill; //same as delete root
                // root = nullptr; //just in case something else has a reference to this memory?
                return nullptr;
            }
            //case 2: kill has one child. can't be zero or we'd enter block above
            else if (!root->left || !root->right) {
                if (root->left == nullptr) {
                    root = root->right;
                } else {
                    root = root->left;
                }
            }
            //case 3: kill has two children
            else {
                //need to find either (1) smallest node greater than root,
                //or (2) largest node smaller than root. either of these will
                //have at most one child. arbitrarily choose (2)
                TreeNode* prev = root;
                root = root->left;
                while (root->right) {
                    prev = root;
                    root = root->right;
                }
                //root now has no right child
                //same logic whether it (1) has left child or (2) is a leaf
                if (kill->left != root) {
                    prev->right = root->left;
                    root->left = kill->left;
                }
                root->right = kill->right;
            }
            //for cases (2) and (3), we will delete kill and return root
            // delete kill;
            return root;
        }
        //if we made it here, we deleted the proper node, so return this subtree
        return root;
    }
};