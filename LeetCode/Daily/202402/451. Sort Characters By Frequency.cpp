#define pic pair<int, char>

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto c : s) mp[c]++;

        priority_queue<pic> pq;
        for(auto [key, val] : mp) pq.push({val, key});

        string res = "";
        while(!pq.empty()) {
            pic now = pq.top();
            pq.pop();

            while(now.first--) res += now.second;
        }

        return res;
    }
};