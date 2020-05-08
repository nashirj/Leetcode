/**
In a binary tree, the root node is at depth 0, and children of 
    ach depth k node are at depth k+1.
Two nodes of a binary tree are cousins if they have the same
    depth, but have different parents.

We are given the root of a binary tree with unique values, and
    the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the
    values x and y are cousins.

Example 1:
Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:
Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Example 3:
Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Note:
The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
*/

// Iterative BFS solution inspired by https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/discuss/239376/Java-BFS-time-and-space-beat-100
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) {
            return false;
        }
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            bool a_exists = false, b_exists = false;
            int size_of_row = nodes.size();
            // iterate over one level at a time, so smart!!! (not my idea)
            for (int i = 0; i < size_of_row; i++) {
                TreeNode* curr = nodes.front();
                nodes.pop();
                if (curr->val == x) {
                    a_exists = true;
                }
                if (curr->val == y) {
                    b_exists = true;
                }
                if (curr->left && curr->right) {
                    // if x and y share a parent
                    if (curr->left->val == x && curr->right->val == y) {
                        return false;
                    }
                    if (curr->left->val == y && curr->right->val == x) {
                        return false;
                    }
                }
                if (curr->left) {
                    nodes.push(curr->left);
                }
                if (curr->right) {
                    nodes.push(curr->right);
                }
            }
            if (a_exists && b_exists) {
                return true;
            }
            // if we found only one, then we know that the nodes are on different levels
            if (a_exists || b_exists) {
                return false;
            }
        }
        return false;
    }
};

// My recursive solution

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root || root->val == x || root->val == y) {
            return false;
        }
        pair<TreeNode*, int> xParent = findParent(root, x, 0);
        pair<TreeNode*, int> yParent = findParent(root, y, 0);
        return (xParent.first != yParent.first && xParent.second == yParent.second);
    }
    pair<TreeNode*, int> findParent(TreeNode* root, int val, int pDepth) {
        if (!root) {
            return pair<TreeNode*, int>();
        }
        pair<TreeNode*, int> res;
        if (root->left) {
            if (root->left->val == val) {
                return pair<TreeNode*, int>(root, pDepth);
            } else {
                res = findParent(root->left, val, pDepth+1);
                if (res.first) {
                    return res;
                }
            }
        }
        if (root->right) {
            if (root->right->val == val) {
                return pair<TreeNode*, int>(root, pDepth);
            } else {
                res = findParent(root->right, val, pDepth+1);
                if (res.first) {
                    return res;
                }
            }
        }
        return pair<TreeNode*, int>();
    }
};






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