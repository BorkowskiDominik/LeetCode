class MinStack {
    // in stack there is a pair of values
    // first -> actual value
    // second -> minimal value at this level
    std::stack<std::pair<int, int>> _stack {};
public:
    MinStack() {}
    
    void push(int val) {
        if (_stack.empty()) {
            _stack.emplace(val, val);
        } else {
            _stack.emplace(val, std::min(val, _stack.top().second));
        }
    }
    
    void pop() {
        _stack.pop();
    }
    
    int top() {
        return _stack.top().first;
    }
    
    int getMin() {
        return _stack.top().second;
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