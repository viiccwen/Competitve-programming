class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        vector<string> v;

        for (string s : words) mp[s]++;

        for (auto i : mp) v.push_back(i.first);

        sort(v.begin(), v.end(), [&](const string& a, const string& b) {
            if (mp[a] != mp[b]) return mp[a] > mp[b];
            else return a > b;
            });

        return vector<string>(v.begin(), v.begin() + k);
    }
};