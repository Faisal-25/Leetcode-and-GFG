class MinStack {
    stack<int> s;
    stack<int> ms;
public:
    MinStack() {
        stack<int> s;
        stack<int> ms;
    }
    
    void push(int val) {
        s.push(val);
        if(ms.size() == 0){
            ms.push(val);
        }
        else if(ms.top()>=val){
            ms.push(val);
        }
    }
    
    void pop() {
        if(s.top() == ms.top()){
            s.pop();
            ms.pop();
            return;
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ms.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */