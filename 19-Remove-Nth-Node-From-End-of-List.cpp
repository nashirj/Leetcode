/*
19. Remove Nth Node From End of List
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/

/*
APPROACH 2
1 pass, set fast and slow n nodes apart, then increment until fast->next == null
O(1) space, O(n) time
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 0;
        ListNode *curr, *del;
        del = curr = head;
        while (i < n){
            del = del->next;
            i++;
        }
        if (!del){
            head = head->next;
            delete curr;
            return head;
        }
        while(del->next){
            curr = curr->next;
            del = del->next;
        }
        del = curr->next;
        curr->next = del->next;
        delete del;
        return head;
    }
};

/*
APPROACH 1
2 passes, get length of list, then remove nth node from end
O(1) space, O(n) time

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return nullptr;
        ListNode* curr;
        curr = head;
        int numNodes = 0;
        while(curr){
            curr = curr->next;
            numNodes++;
        }
        int i = 0;
        curr = head;
        int prev = numNodes-n-1;
        if(prev == -1){
            head = head->next;
            delete curr;
        }
        else{
            while(i < prev){
                curr = curr->next;
                i++;
            }
            ListNode* kill = curr->next;
            curr->next = kill->next;
            delete kill;
        }
        return head;
    }
};
*/