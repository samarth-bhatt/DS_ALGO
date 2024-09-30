class CustomStack {
private:
    deque<int>st;
    int mx;
    int currSize = 0;
public:
    CustomStack(int maxSize) {
        mx = maxSize;
    }
    
    void push(int x) {
        if(currSize < mx){
            st.push_back(x);
            currSize++;
        }
    }
    
    int pop() {
        if(currSize == 0) return -1;
        else{
            int toBeRemoved = st.back();
            st.pop_back();
            currSize--;
            return toBeRemoved;
        }
    }
    
    void increment(int k, int val) {
        deque<int>aux;
        while(!st.empty() && k--){
            aux.push_back(st.front() + val);
            st.pop_front();
        }
        while(!aux.empty()){
            st.push_front(aux.back());
            aux.pop_back();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */