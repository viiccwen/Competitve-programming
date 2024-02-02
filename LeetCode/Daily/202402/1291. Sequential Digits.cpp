class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        vector<int> ans;

        for(int i=1; i<=9; ++i) q.push(i);

        while(!q.empty()) {
            int val = q.front(); q.pop();
            
            if(val >= low && val <= high) ans.emplace_back(val);
            
            int end = val % 10;
            if(end == 9) continue;

            val = val * 10 + (end + 1); 

            q.push(val);
        }

        return ans;
    }
};