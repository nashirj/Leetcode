/*
897. Increasing Order BST
Given a tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9  
Note:

The number of nodes in the given tree will be between 1 and 100.
Each node will have a unique integer value from 0 to 1000.
*/

//APPROACH 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        //Approach 2
        //do in order traversal, add every ptr to a vector, rearrange tree from vector
        /*
            1) Create an empty stack S.
            2) Initialize current node as root
            3) Push the current node to S and set current = current->left until current is NULL
            4) If current is NULL and stack is not empty then 
                a) Pop the top item from stack.
                b) Print the popped item, set current = popped_item->right 
                c) Go to step 3.
            5) If current is NULL and stack is empty then we are done.
        */
        
        TreeNode *top = root;
        
        vector<TreeNode*> tptrs;
        vector<TreeNode*> vals;
        
        while(true){
            while(top != nullptr){
                tptrs.push_back(top);
                top = top->left;
            }
            
            if(tptrs.size() == 0)
                break;
            
            cout << tptrs.back()->val << endl;
            vals.push_back(tptrs.back());
            top = tptrs.back()->right;
            tptrs.pop_back();
        }
        
        
        TreeNode* new_tree = vals[0];
        TreeNode* iterator = new_tree;
        iterator->left = nullptr;
        
        
        for(int i = 1; i < vals.size(); i++){
            iterator->right = vals[i];
            iterator->left = nullptr;
            iterator = iterator->right;
        }
        
        
        return new_tree;
    }
};

//APPROACH 2 - NEED TO FINISHED
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        //Approach 2
        //do in order traversal, add every ptr to a vector, rearrange tree from vector
        /*
            1) Create an empty stack S.
            2) Initialize current node as root
            3) Push the current node to S and set current = current->left until current is NULL
            4) If current is NULL and stack is not empty then 
                a) Pop the top item from stack.
                b) Print the popped item, set current = popped_item->right 
                c) Go to step 3.
            5) If current is NULL and stack is empty then we are done.
        */
        
        TreeNode *top = root;
        
        vector<TreeNode*> tptrs;
        vector<TreeNode*> vals;
        
        while(true){
            while(top != nullptr){
                tptrs.push_back(top);
                top = top->left;
            }
            
            if(tptrs.size() == 0)
                break;
            
            cout << tptrs.back()->val << endl;
            vals.push_back(tptrs.back());
            top = tptrs.back()->right;
            tptrs.pop_back();
        }
        
        
        TreeNode* new_tree = vals[0];
        TreeNode* iterator = new_tree;
        iterator->left = nullptr;
        
        for(int i = 1; i < vals.size(); i++){
            iterator->right = vals[i];
            iterator->left = nullptr;
            iterator = iterator->right;
        }
        
        
        return new_tree;
    }
};