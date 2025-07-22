class MyQueue {
    std::stack<int> s1, s2;

    void transferIfNeeded() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        transferIfNeeded();
        int res = s2.top();
        s2.pop();
        return res;
    }
    
    int peek() {
        transferIfNeeded();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};


// class MyQueue {
//     std::stack<int> s1;
//     std::stack<int> s2;

//     void shift_all(stack<int>& source, stack<int>& dest) {
//         while (!source.empty()){
//             dest.push(source.top());
//             source.pop();
//         }
//     }

// public:
//     MyQueue() {
        
//     }
    
//     void push(int x) {
//         // Pushes element x to the back of the queue.
//         s1.push(x);
//     }
    
//     int pop() {
//         //  Removes the element from the front of the queue and returns it.
//         shift_all(s1, s2);
//         auto res = s2.top();
//         s2.pop();
//         shift_all(s2, s1);
//         return res;
//     }
    
//     int peek() {
//         // Returns the element at the front of the queue
//         shift_all(s1, s2);
//         auto res = s2.top();
//         shift_all(s2, s1);
//         return res;
//     }
    
//     bool empty() {
//         return s1.empty() && s2.empty();   
//     }
// };

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */