class MinStack {
public:
        stack<int> st;
        stack<int> minNum;
    MinStack() {

    }
    
    void push(int value) {
        st.push(value);
        if(minNum.empty() || value <= minNum.top())
            minNum.push(value);
    }
    
    void pop() {
        int stTop = st.top();
        st.pop();
        if(minNum.top() == stTop)
            minNum.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minNum.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */