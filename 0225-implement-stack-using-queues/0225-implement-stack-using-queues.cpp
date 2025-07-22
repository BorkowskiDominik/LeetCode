class MyStack {
    std::queue<int> que;
public:
    MyStack() {
        // _v.reserve(20);
    }
    
    void push(int x) {
        // Pushes element x to the top of the stack
        que.push(x);
    }
    
    int pop() {
        // Removes the element on the top of the stack and returns it.
        // I can only pop from front
        auto q_size = que.size();
        if (!q_size) return -1;
        for (int i = 0; i < q_size -1; ++i) {
            que.push(que.front());
            que.pop();
        }
        auto res = que.front();
        que.pop();
        return res;
    }
    
    int top() {
        // Returns the element on the top of the stack.
        auto q_size = que.size();
        if (!q_size) return -1;
        // rotate queue
        for (int i = 0; i < q_size - 1; ++i) {
            que.push(que.front());
            que.pop();
        }
        auto res = que.front();
        que.push(que.front());
        que.pop();
        return res;
    }
    
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */