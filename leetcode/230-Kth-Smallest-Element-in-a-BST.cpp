/*
230. Kth Smallest Element in a BST

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:
Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
*/


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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return helper(root, k, count);
    }
    int helper(TreeNode* root, int k, int& count) {
        if (!root) {
            return INT_MIN;
        }
        int left = helper(root->left, k, count);
        if (left != INT_MIN) {
            return left;
        }
        
        count++;
        if (count == k) {
            return root->val;
        }
        
        return helper(root->right, k, count);
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
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vals;
        //create a sorted vector with k values, the k-1th element is the largest of the k vals
        kthSmallest(root, k, vals);
        return vals[k-1];
    }
    void kthSmallest(TreeNode* root, int k, vector<int>& vals) {
        //in order traversal, add elements if they have no left child
        if (vals.size() == k)
            return;
        if (root->left) {
            kthSmallest(root->left, k, vals);
        }
        vals.push_back(root->val);
        if (root->right) {
            kthSmallest(root->right, k, vals);
        }
        return;
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
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        //count the number of nodes in left subtree
        int num_nodes = countNodes(root->left);
        
        //if there are k-1 nodes to the left, kth smallest is root
        if (num_nodes == k-1) {
            return root->val;
        }
        //else if there are at least k nodes to the left, kthSmallest is in left subtree
        else if (num_nodes >= k) {
            return kthSmallest(root->left, k);
        }
        //else if not to the left and not root, kthSmallest is in right subtree
        //we now only care about right subtree, so reduce k by root (1) and left subtree (num_nodes)
        else {
            return kthSmallest(root->right, k-num_nodes-1);
        }
    }
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        //number of nodes in subtrees + 1 for current node
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

