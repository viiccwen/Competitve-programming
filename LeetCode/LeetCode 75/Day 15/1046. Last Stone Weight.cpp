//vector

class Solution {
public:
    void EraseVal(vector<int>& stones, vector<int>::iterator ite) {
        ite = stones.begin();
        stones.erase(ite, ite + 2);
    }
    int lastStoneWeight(vector<int>& stones) {
        int x, y;
        vector<int>::iterator ite;
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end(), [](int a, int b) { return a > b; });
            y = stones[0], x = stones[1];
            EraseVal(stones, ite);

            if (x < y) stones.push_back(y - x);
        }

        if (stones.size() != 0) return stones[0];
        else return 0;
    }
};

// priority_queue

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int x, y;

        for (int i : stones) pq.push(i);

        while (pq.size() >= 2) {
            y = pq.top(), pq.pop();
            x = pq.top(), pq.pop();
            if (y > x) pq.push(y - x);
        }
        if (!pq.empty()) return pq.top();
        else return 0;
    }
};