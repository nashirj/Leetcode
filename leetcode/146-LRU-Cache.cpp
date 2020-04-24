/**
146. LRU Cache
Design and implement a data structure for Least Recently Used (LRU) cache. It should support
    the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache,
    otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache
    reached its capacity, it should invalidate the least recently used item before inserting
    a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache(2); // capacity = 2

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/


struct DLListNode {
    int val;
    int key;
    DLListNode *next;
    DLListNode *prev;
    DLListNode(int x, int y) : val(x), key(y), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    map<int, DLListNode*> vals;
    DLListNode* head;
    DLListNode* tail;
    int capacity;
    int num_elements;
public:
    /**
     * use a hashmap and a doubly linked list
     */
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->num_elements = 0;
        this->head = this->tail = nullptr;
    }
    
    void removeLRU() {
        int key = tail->key;
        vals.erase(key);
        
        if (num_elements > 1) {
            DLListNode* prev = this->tail->prev;
            prev->next = nullptr;

            delete this->tail;
            this->tail = prev;
        } else {
            delete this->tail;
            this->tail = this->head = nullptr;
        }
        
        this->num_elements--;
    }
    
    int get(int key) {
        if (this->vals.find(key) == this->vals.end()) {
            return -1;
        }
        
        DLListNode* node = this->vals.find(key)->second;
        DLListNode* prev = node->prev;
        if (node == head) {
            // do nothing
        } else if (node == tail) {
            tail = prev;
            prev->next = nullptr;
        } else { // interior
            prev->next = node->next;
            prev->next->prev = prev;
        }
        
        if (node != head) {
            node->next = this->head;
            node->prev = nullptr;
            this->head->prev = node;
            this->head = node;
        }
        
        return head->val;
    }
    
    void put(int key, int value) {
        if (this->vals.find(key) != this->vals.end()) {
            this->vals.find(key)->second->val = value;
            this->get(key); // move this to front of LRU
            return;
        }
        
        if (this->capacity == this->num_elements) {
            this->removeLRU();
        }
        
        DLListNode* new_node = new DLListNode(value, key);
        new_node->next = this->head;
        if (this->head) {
            this->head->prev = new_node;
        }
        this->head = new_node;
        this->vals[key] = new_node;
        this->num_elements++;
        if (!tail) {
            this->tail = new_node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */