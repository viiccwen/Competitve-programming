class MyQueue {
public:
    stack<int> sk1, sk2;

    MyQueue() {

    }

    void push(int x) {
        while (!sk1.empty()) {
            sk2.push(sk1.top());
            sk1.pop();
        }

        sk2.push(x);

        while (!sk2.empty()) {
            sk1.push(sk2.top());
            sk2.pop();
        }
    }

    int pop() {
        int p = sk1.top();
        sk1.pop();

        return p;
    }

    int peek() {
        return sk1.top();
    }

    bool empty() {
        return sk1.empty();
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