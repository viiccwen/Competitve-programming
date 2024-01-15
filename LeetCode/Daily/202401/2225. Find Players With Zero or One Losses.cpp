class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp;
        int n = matches.size();

        for(int i=0; i<n; ++i) mp[matches[i][1]]++;

        vector<int> notLose, onceLose;
        for(int i=0; i<n; ++i) {
            int win = matches[i][0];
            int los = matches[i][1];

            if(mp.find(win) == mp.end()) {
                notLose.emplace_back(win);
                mp[win] = 2;
            }

            if(mp[los] == 1) onceLose.emplace_back(los);
        }

        sort(notLose.begin(), notLose.end());
        sort(onceLose.begin(), onceLose.end());

        return {notLose, onceLose};
    }
};