class MyStack {
public:
    queue<int>a,b; //a is the main queue and b is auxilary queue
    MyStack() {
        /*according to the given MyStack structure, we have to 
        make pop operation costly.*/
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        if(a.empty()){
            return -1;
        }
        int poppedItem = a.back();
        while(a.size()!=1){
            b.push(a.front());
            a.pop();
        }
        a.pop();
        while(!b.empty()){
            a.push(b.front());
            b.pop();
        }
        return poppedItem;
    }
    
    int top() {
        return a.back();
    }
    
    bool empty() {
        return a.empty();
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