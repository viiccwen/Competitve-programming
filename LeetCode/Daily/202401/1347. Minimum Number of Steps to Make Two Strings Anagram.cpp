class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mp;
        int minStep = 0;
        for(auto c : s) mp[c]++;
        for(auto c : t) {
            if(mp.find(c) != mp.end() && mp[c] > 0) mp[c]--;
        }
        for(auto [_, val] : mp) minStep += val;

        return minStep;
    }
};