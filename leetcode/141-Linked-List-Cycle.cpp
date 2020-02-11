/*
141. Linked List Cycle
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
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
    //O(1) space, O(n) time
    bool hasCycle(ListNode *head) {
        //if list is of size 1 or 0, no cycle
        if (!head || !head->next)
            return false;
        
        //slow moves 1 step at a time, fast moves 2 steps at a time
        ListNode *slow, *fast;
        
        //initialize slow and fast
        slow = head->next; //1 step
        fast = head->next->next; //2 steps
        
        //if either slow or fast are nullptr, no cycle
        while(slow && fast){
            if (slow == fast)
                return true;
            slow = slow->next;
            //ensure we don't access next of nullptr
            if (fast->next){
                fast = fast->next->next;
            }
            //if fast->next == nullptr, then no cycle
            else
                break;
        }
        
        return false;
        
    }
};


/*

class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> nodes;
        ListNode* curr = head;
        
        while(curr){
            if (nodes.find(curr) != nodes.end())
                return true;
            else
                nodes.insert(curr);
            curr = curr->next;
        }
        
        return false;
        
    }
};


*/