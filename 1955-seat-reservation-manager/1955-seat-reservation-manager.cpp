class SeatManager {
private:
    vector<bool>seats;
    // int smallestUnrevservedSeatNo = 1;
    // int smallestFreed = 1;
    // int total_seats;
    priority_queue<int, vector<int>, greater<int>> available_seats;
public:
    SeatManager(int n) {
        seats.resize(n+1, false);
        // total_seats = n;
        for(int i=1; i<=n; i++) available_seats.push(i);
    }
    
    int reserve() {
        // if(smallestFreed < smallestUnrevservedSeatNo){
        //     seats[smallestFreed] = true;
        //     if(smallestFreed < total_seats && seats[smallestFreed+1] == false)
        //         smallestFreed++;
        //     else 
        //         smallestFreed = smallestUnrevservedSeatNo;
        // }
        if(available_seats.size() > 0){
            int seatNumber = available_seats.top();
            available_seats.pop();
            seats[seatNumber] = true;
            return seatNumber;
        } else return -1; // not available
    }
    
    void unreserve(int seatNumber) {
        // seats[seatNumber] = false;
        // if(seatNumber < smallestUnrevservedSeatNo) smallestFreed = seatNumber;
        // else smallestUnrevservedSeatNo--;
        seats[seatNumber] = false;
        available_seats.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */