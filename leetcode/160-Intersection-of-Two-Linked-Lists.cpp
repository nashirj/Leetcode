
//this one is not mine.. but wow
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA, *ptr2 = headB;
        while (ptr1 != ptr2) {
            ptr1 = ptr1 ? ptr1->next : headB;
            ptr2 = ptr2 ? ptr2->next : headA;
            //if they are ever both null, nullptr is returned since there is no intersection wowzers
        }
        return ptr1;
    }
};





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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return nullptr;
        
        ListNode *a = headA, *b = headB;
        int asize = 0, bsize = 0;
        
        while (a->next)
            a = a->next;
        while (b->next)
            b = b->next;
        if (b != a)
            return nullptr;
        
        ListNode* end = a; //or b
        
        a = headA;
        b = headB;
        
        bool pa = true, pb = true;
        
        while (true){
            if (a == b)
                return a; //return b
            if (a == end){
                pa ? a = headB : a = headA;
                pa = !pa;
            }   
            else
                a = a->next;
                
            if (b == end){
                pb ? b = headA : b = headB;
                pb = !pb;
            }
            else
                b = b->next;
        }
        
        return nullptr;
        
    }
};





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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while (a){
            ListNode* bRunner = b;
            while (bRunner){
                if (a == bRunner)
                    return a; //return bRunner;
                bRunner = bRunner->next;
            }
            a = a->next;
        }
        
        return nullptr;
        
    }
};



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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        int asize, bsize;
        asize = bsize = 0;
        while (a){
            asize++;
            a = a->next;
        }
        while (b){
            bsize++;
            b = b->next;
        }
        
        int diff = asize - bsize;
        b = headB;
        a = headA;
        //if diff < 0 list b is larger, if > 0 list a is larger, if == 0, same size
        if (diff < 0){
            diff = -diff;
            while (diff > 0){
                b = b->next;
                diff--;
            }
        }
        else if (diff > 0){
            while (diff > 0){
                a = a->next;
                diff--;
            }
        }
        //else
            //do nothing
        
        while (a && b){
            if (a == b)
                return a; //return b;
            a = a->next;
            b = b->next;
        }
        
        return nullptr;
        
    }
};


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return nullptr;
        unordered_set<ListNode*> seen;
        ListNode *a = headA, *b = headB;
        while (a){
            seen.insert(a);
            a = a->next;
        }
        while (b){
            if (seen.find(b) != seen.end())
                return b;
            b = b->next;
        }
        return nullptr;
        
    }
};