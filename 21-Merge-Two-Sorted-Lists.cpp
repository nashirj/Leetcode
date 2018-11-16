/*
21. Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

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
	//recursive solution - O(n) space, O(n) time
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	//base case, if either list is empty, return other list - if both are empty, returns nullptr
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode *curr;
        
        //assign node with smaller value to curr
        if (l1->val <= l2->val){
            curr = l1;
            //recursive call, makes l1 smaller
            curr->next = mergeTwoLists(l1->next, l2);
        }
        else{
            curr = l2;
            //recursive call, decreases l2 smaller
            curr->next = mergeTwoLists(l1, l2->next);
        }
        return curr;        
    }
};



/*
class Solution {
public:
	//iterative solution, O(1) space, O(n) time
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        else if (!l2) return l1;
        
        ListNode *head, *curr;
		
		//initialize head ptr        
        if (l1->val <= l2->val){
            head = l1;
            l1 = l1->next;
        }
        else{
            head = l2;
            l2 = l2->next;
        }

        curr = head;
		
		//iterate through nodes, get smaller valued node each time
        while(l1 && l2){
            if (l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            }
            else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        //check to see if any of l1 or l2 remains
        if (l1){
            curr->next = l1;
        }
        if (l2){
            curr->next = l2;
        }
        
        return head;
        
    }
};
*/