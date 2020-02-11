/*
24. Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head) {
        //what if it is odd? should we assume it is even?
        if (!head || !head->next)
            return head;
        ListNode* first = head->next;
        ListNode* second = head;
        
        second->next = first->next;
        first->next = second;
        
        second->next = swapPairs(second->next);
        
        return first;
    }
};