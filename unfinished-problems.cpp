//finish count primes
//finish valid sudoku



//IMPLEMENT LINKED LIST


class Node{
public:
    int val;
    Node* next;
    Node(int value){
        val = value;
        next = NULL;
    }
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        Node* head = NULL;
        list_len = 0;
        cout << "created list" << endl;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        cout << "getting value" << endl;
        Node *p = head;
        int counter = 0;
        while (p != NULL){
            if (counter == index){
                return p->val;
            }
            p = p->next;
            counter++;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        addAtIndex(0, val);
        cout << "added to head" << endl;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        addAtIndex(list_len, val);
        cout << "added to tail" << endl;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > list_len){
            cout << "invalid index" << endl;
            return;
        }
        if (index == 0){
            cout << "adding to front";
            Node* p = new Node(val);
            p->next = head;
            head = p;
            list_len++;
            return;
        }
        
        Node *p = head;
        int counter = 1;
        while (p->next != NULL){
            if (counter == index){
                cout << "adding to middle" << endl;
                Node* n = new Node(val);
                n->next = p->next;
                p->next = n;
                list_len++;
                return;                
            }
            p = p->next;
            counter++;
        }
        //if end
        cout << "adding to end" << endl;
        Node* n = new Node(val);
        p->next = n;
        list_len++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        
        cout << "deleting index" << endl;
        if (index < 0 || index >= list_len)
            return;
        Node* p = head;
        if (index == 0){
            head = p->next;
            delete p;
            list_len--;
            return;
        }
        
        int counter = 1;
        while (p->next != NULL){
            if (counter == index){
                Node* d = p->next;
                p->next = d->next;
                delete d;
                list_len--;
                return;
            }
            p = p->next;
            counter++;
        }        
        
    }
    void printList(){
        Node* p = head;
        while (p != NULL){
            cout << p->val << endl;
            p = p->next;
        }
    }
private:
    Node* head;
    int list_len;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */









//FLIP AND INVERT IMAGE

 class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int len = A.size();
        
        if (len == 0)
            return A;
        if (len == 1){
            if (A[0][0] == 0)
                A[0][0] = 1;
            else
                A[0][0] = 0;
        }
        
        int iterator;
        
        if (len % 2 == 0)
            iterator = (len/2) - 1;
        else
            iterator = len/2;
        
        int temp;
        for (int i = 0; i < len; i++){
            for (int j = 0; j < iterator; i++){
                temp = A[i][j];
                A[i][j] = A[i][len-j-1];
                A[i][len-j-1] = temp;
                if (A[i][j] == A[i][len-j-1]){
                    if (A[i][j] == 1)
                        A[i][j] = 0;
                    else
                        A[i][j] = 1;
                }
                
                if (A[i][j] == 1)
                    A[i][j] = 0;
                else
                    A[i][j] = 1;
            
                if (A[i][len-j-1] == 1)
                    A[i][len-j-1] = 0;
                else
                    A[i][len-j-1] = 1;
            }
        }
        return A;
    }
};





//FIRST BAD VERSION

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        /*
        //brute force
        int counter = 1;
        while(counter <= n){
            if (isBadVersion(counter))
                return counter;
            counter++;
        }
        //binary search - still too slow!
        int lower = 1, middle;
        bool isBad, isBadBelow;
        while(lower < n){
            middle = (n+lower)/2;
            isBad = isBadVersion(middle);
            isBadBelow = isBadVersion(middle - 1);
            if(isBad && !isBadBelow)
               return middle;
            else if(isBad && isBadBelow)
                n = middle;
            else //if(!isBad)
                lower = (lower < middle) ? middle : lower + 1;
        }
        return n;
        */
        //binary search, one call per iteration
        int lower = 1, middle;
        bool isBad, isBadBelow;
        while(lower < n){
            middle = (n+lower)/2;
            isBad = isBadVersion(middle);
            isBadBelow = isBadVersion(middle - 1);
            if(isBad){
                
            } && !isBadBelow)
               return middle;
            else if(isBad && isBadBelow)
                n = middle;
            else //if(!isBad)
                lower = (lower < middle) ? middle : lower + 1;
        }
        return n;
    }
};