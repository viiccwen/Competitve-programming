class SeatManager {
 public:
  int last;
  priority_queue<int, vector<int>, greater<int>> pq;
  SeatManager(int n) { last = 0; }

  int reserve() {
    if (pq.empty()) {
      last++;
      return last;
    } else {
      int front = pq.top();
      pq.pop();
      return front;
    }
  }

  void unreserve(int seatNumber) {
    if (last == seatNumber)
      last--;
    else
      pq.push(seatNumber);
  }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */