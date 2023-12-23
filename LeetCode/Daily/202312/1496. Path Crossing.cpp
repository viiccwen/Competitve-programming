class Solution {
public:
    bool isPathCrossing(string path) {
        pair<int, int> point = {0, 0};
        unordered_map<char, pair<int, int>> mp{{'N',{-1, 0}}, {'E', {0, 1}}, {'S', {1, 0}}, {'W', {0, -1}}};
        set<pair<int, int>> s{{0, 0}};

        for(auto p : path) {
            point.first += mp[p].first;
            point.second += mp[p].second;
            if(s.find(point) != s.end()) return true;
            s.insert(point);
        }

        return false;
    }
};