/**
155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/


/**
Two stack solution
We push the minimum to the min stack if the min stack is empty or if it is less than the current min,
which is the value at min_stck.top(). the bottom most element in stck is also in min_stck, so even if
no other vals are added, there is no risk of min_stck becoming empty before stck does, and if min is
popped from stack, it is also popped from min stack
*/
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stck;
    stack<int> min_stck;
    
    MinStack() {}
    
    void push(int x) {
        stck.push(x);
        if (min_stck.empty() || x <= min_stck.top())
            min_stck.push(x);
    }
    
    int top() {
        return stck.top();
    }
    
    void pop() {
        int top = stck.top();
        stck.pop();
        if (top == min_stck.top()) {
            min_stck.pop();
        }
    }
    
    int getMin() {
        return min_stck.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
public:
    /** initialize your data structure here. */
    multiset<int> vals; // can't use a normal set because there may be two occurences of the min
    stack<int> stck;
    int size;
    MinStack() {
        size = 0;
    }
    
    void push(int x) {
        stck.push(x);
        vals.insert(x);
        size++;
    }
    
    int top() {
        if (isEmpty()) {
            return -1;
        }
        return stck.top();
    }
    
    void pop() {
        if (isEmpty()) {
            return;
        }
        int top = stck.top();
        stck.pop();
        size--;
        // erase from multiset
        multiset<int>::iterator it(vals.find(top));
        if (it != vals.end()) {
            vals.erase(it);
        }
    }
    
    int getMin() {
        if (isEmpty()) {
            return -1;
        }
        return *vals.begin();
    }
    
    bool isEmpty() {
        return (size == 0);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */class MinStack {
public:
    /** initialize your data structure here. */
    multiset<int> vals; // can't use a normal set because there may be two occurences of the min
    stack<int> stck;
    int size;
    MinStack() {
        size = 0;
    }
    
    void push(int x) {
        stck.push(x);
        vals.insert(x);
        size++;
    }
    
    int top() {
        if (isEmpty()) {
            return -1;
        }
        return stck.top();
    }
    
    void pop() {
        if (isEmpty()) {
            return;
        }
        int top = stck.top();
        stck.pop();
        size--;
        // erase from multiset
        multiset<int>::iterator it(vals.find(top));
        if (it != vals.end()) {
            vals.erase(it);
        }
    }
    
    int getMin() {
        if (isEmpty()) {
            return -1;
        }
        return *vals.begin();
    }
    
    bool isEmpty() {
        return (size == 0);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */