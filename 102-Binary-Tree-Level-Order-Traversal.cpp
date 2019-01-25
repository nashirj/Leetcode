/*
102. Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
*/

//since every node must be processed, O(n) time complexity, and since every node is added to the queue, also O(n) space complexity

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        
        ans.push_back(vector<int>());
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        //first row has 1 node, otherwise would have returned at beginning
        int row = 0, processedNodes = 0, nextRow = 0, nodesInRow = 1;
        
        //count number of nodes in the next row (starting with root), go to next row when all nodes
        //in the current row have been processed, repeat for all rows (until there are no more nodes in the queue)
        while (!(nodes.empty())){
            if (processedNodes == nodesInRow){
                ans.push_back(vector<int>());
                row++;
                nodesInRow = nextRow;
                processedNodes = 0;
                nextRow = 0;
            }
            
            TreeNode* curr = nodes.front();
            nodes.pop();
            
            //count children of current node
            if (curr->left){
                nextRow++;
                nodes.push(curr->left);
            }
            if (curr->right){
                nextRow++;
                nodes.push(curr->right);
            }
            
            ans[row].push_back(curr->val); //add current node to vector
            processedNodes++;
        }
        
        return ans;
    }
};



/*
first approach, duplicated code
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        //everytime I check for curr->left or curr->right, increment counter (initially 1)
        //everytime counter = 2^row - 1, push_back new row (initially 1)
        
        if (!root)
            return vector<vector<int>>();
        
        vector<vector<int>> ans(1);
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        //count values in 2nd level of tree (1st below root)
        int nextRow = 0;
        
        if (root->left){
            nextRow++;
            nodes.push(root->left);
        }
        if (root->right){
            nextRow++;
            nodes.push(root->right);
        }
        
        nodes.pop();
        
        ans[0].push_back(root->val);
        if (nextRow != 0)
            ans.push_back(vector<int>());
        
        int row = 1, nodesInRow = 0;
        int currRow = nextRow;
        nextRow = 0;
        
        while (!(nodes.empty())){
            
            //count number of nodes in the next row (starting with root), go to next row when all nodes have been processed, repeat for all rows
            if (nodesInRow == currRow){
                ans.push_back(vector<int>());
                row++;
                currRow = nextRow;
                nodesInRow = 0;
                nextRow = 0;
            }
            
            TreeNode* curr = nodes.front();
            if (curr->left){
                nextRow++;
                nodes.push(curr->left);
            }
            if (curr->right){
                nextRow++;
                nodes.push(curr->right);
            }
            
            ans[row].push_back(curr->val);
            nodes.pop();
            
            nodesInRow++;
        }
        
        return ans;
    }
};