class MedianFinder {
public:
    priority_queue<int>mini;
    priority_queue<int, vector<int>, greater<int>>maxi;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(mini.empty() && maxi.empty()){
            mini.push(num);
            return;
        }
        if(mini.size() == maxi.size()){
            if(mini.top() > num){
                int x = mini.top();
                mini.pop();
                maxi.push(x);
                mini.push(num);
                // Added rebalance
                if (maxi.size() > mini.size()) {
                    mini.push(maxi.top());
                    maxi.pop();
                }
            } else{
                maxi.push(num);
                int x = maxi.top();
                maxi.pop();
                mini.push(x);
            }
        } else{
            maxi.push(num);

            if (maxi.top() < mini.top()) {
                int x = mini.top();
                mini.pop();

                int y = maxi.top();
                maxi.pop();

                mini.push(y);
                maxi.push(x);
            }

            // Added rebalance
            if (maxi.size() > mini.size()) {
                mini.push(maxi.top());
                maxi.pop();
            }
        }
    }
    
    double findMedian() {
        if(mini.size() > maxi.size()) return mini.top();
        else if(mini.size() < maxi.size()) return maxi.top();
        else return (mini.top() + maxi.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */