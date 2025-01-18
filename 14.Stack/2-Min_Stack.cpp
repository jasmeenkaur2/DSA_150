#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainstack; // Stack to store all elements
    stack<int> minstack;  // Stack to store minimum elements

public:
    // Constructor to initialize the stacks
    MinStack() {
    }
    
    // Push an element onto the stack
    void push(int val) {
        mainstack.push(val);
        // Update the minstack only if it's empty or the new value is less than or equal to the current minimum
        if (minstack.empty() || val <= minstack.top()) {
            minstack.push(val);
        }
    }
    
    // Remove the top element of the stack
    void pop() {
        // If the top of mainstack is the same as the top of minstack, pop minstack too
        if (mainstack.top() == minstack.top()) {
            minstack.pop();
        }
        mainstack.pop();
    }
    
    // Get the top element of the stack
    int top() {
        return mainstack.top();
    }
    
    // Get the current minimum element
    int getMin() {
        return minstack.top();
    }
};

// Driver Code
int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);

    // Get the minimum value
    cout << "Current Min: " << obj->getMin() << endl; // Output: -3
    
    // Remove the top element
    obj->pop();
    
    // Get the top value
    cout << "Top Element: " << obj->top() << endl; // Output: 0
    
    // Get the current minimum again
    cout << "Current Min: " << obj->getMin() << endl; // Output: -2

    delete obj;
    return 0;
}
