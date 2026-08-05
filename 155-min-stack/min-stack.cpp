class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    MinStack() {
    }
    
    void push(int value) {
        st.push(value);
        if(minst .empty() || value <= minst.top())
        minst.push(value);
    }
    
    void pop() {
        if(st.size() == 0) return;
         if (st.top() == minst.top())
            minst.pop();
            st.pop();
    }
    
    int top() {
        if(minst.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
          if (minst.empty()) return -1;
        return minst.top();
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