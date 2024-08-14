class MyQueue {
private:
    stack<int>main, aux;
public:
    MyQueue() {
        // Stack's are already Initialized
    }
    
    void push(int x) {
        while(!main.empty()){
            aux.push(main.top());
            main.pop();
        }
        aux.push(x);
        while(!aux.empty()){
            main.push(aux.top());
            aux.pop();
        }
    }
    
    int pop() {
        int top = main.empty() ? -1 : main.top();
        if(!main.empty()) main.pop();
        return top;
    }
    
    int peek() {
        return main.empty() ? -1 : main.top();
    }
    
    bool empty() {
        return main.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */