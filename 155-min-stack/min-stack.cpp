class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if (minstk.empty() || val <= minstk.top()){
            minstk.push(val);
        }
    }
    
    void pop() {
        if (stk.top()==minstk.top()){
            minstk.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstk.top();
    }
private:
    stack<int> stk;
    stack<int> minstk;
};

// do it with 2 stacks, 1 holds the min value on top the other works as normal.

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */