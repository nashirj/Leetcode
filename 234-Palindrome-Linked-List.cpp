/*
234. Palindrome Linked List

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //approach 1, use a stack
    bool isPalindrome(ListNode* head) {
        
        ListNode* it = head;
        int size = 0;
        
        while(it != nullptr){
            size++;
            it = it->next;
        }
        
        int midpoint = size/2;
        vector<int> vals(midpoint);
        
        int i = 0;
        it = head;
        while (i < midpoint){
            vals[i] = it->val;
            cout << vals[i] << endl;
            i++;
            it = it->next;
        }
        //point i to top of stack;
        i--;
        
        bool odd = false;
        if(size % 2 != 0)
            odd = true;
        
        if (odd){
            it = it->next;
        }
        while(it != nullptr){
            if (vals[i] != it->val)
                return false;
            i--;
            it = it->next;
        }
        return true;
    }
};