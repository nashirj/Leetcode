/**
103. Binary Tree Zigzag Level Order Traversal

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]
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
  vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    if (!root) {
      return vector<vector<int> >();
    }
    vector<vector<int> > traversal;

    traversal.push_back(vector<int>());
    traversal[0].push_back(root->val);
    int nodes_below_row = 0;
    queue<TreeNode*> nodes;

    if (root->left) {
      nodes.push(root->left);
      nodes_below_row++;
    }
    if (root->right) {
      nodes.push(root->right);
      nodes_below_row++;
    }
    int curr_pos_in_row = 0;

    if (nodes_below_row != 0) {
      traversal.push_back(vector<int>());
    }
    int curr_row = 1;

    int nodes_curr_row = nodes_below_row;
    nodes_below_row = 0;
    int pos_in_row = 0;

    while (!nodes.empty()) {
      TreeNode* curr = nodes.front();
      nodes.pop();
      if (pos_in_row == nodes_curr_row) {
        traversal.push_back(vector<int>());
        curr_row++;
        nodes_curr_row = nodes_below_row;
        nodes_below_row = 0;
        pos_in_row = 0;
      }

      traversal[curr_row].push_back(curr->val);

      if (curr->left) {
        nodes.push(curr->left);
        nodes_below_row++;
      }
      if (curr->right) {
        nodes.push(curr->right);
        nodes_below_row++;
      }
      pos_in_row++;
    }

    if (traversal.size() > 1) {
      for (int i = 1; i <= curr_row; i += 2) {
        int t_size = traversal[i].size();
        int stopping_point = (t_size / 2);
        for (int j = 0; j < stopping_point; j++) {
          int temp = traversal[i][j];
          traversal[i][j] = traversal[i][t_size - j - 1];
          traversal[i][t_size - j - 1] = temp;
        }
      }
    }


    return traversal;
  }
};