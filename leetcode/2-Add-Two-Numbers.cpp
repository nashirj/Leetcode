/*
2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


// solution from 7/19/20
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // one way is to just reverse and add that way
        // need to be careful when carrying digits
        // if they are not the same length, need to proceed accordingly
        bool carry = false;
        ListNode* lhead = nullptr;
        ListNode* l = nullptr;
        
        while (l1 && l2) {
            int sum = l1->val + l2->val;
            if (carry) {
                sum += 1;
                carry = false;
            }
            if (!lhead) { // initialize lhead
                l = new ListNode(sum % 10);
                lhead = l;
            } else {
                l->next = new ListNode(sum % 10);
                l = l->next;
            }
            carry = ((sum / 10) > 0);
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* remainder = (l1) ? l1 : l2; // at most, one is not nullptr;
        while (remainder) {
            int sum = remainder->val;
            if (carry) {
                sum += 1;
                carry = false;
            }
            if (!lhead) { // initialize lhead
                l = new ListNode(sum % 10);
                lhead = l;
            } else {
                l->next = new ListNode(sum % 10);
                l = l->next;
            }
            carry = ((sum / 10) > 0);
            remainder = remainder->next;
        }
        if (carry) {
            // lhead must be initialized if carry is true
            l->next = new ListNode(1);
        }
        
        return lhead;
    }
};