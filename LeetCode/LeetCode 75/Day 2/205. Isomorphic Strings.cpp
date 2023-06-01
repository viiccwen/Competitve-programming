class Solution {
public:
    string Process(string s) { // input output
        unordered_map<char, pair<int, int>> mp; // first count second index
        string a = "";
        int k = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!mp.count(s[i])) {
                mp[s[i]].first = 0;
                mp[s[i]].second = i;
                a += '0';
                continue;
            }
            else if (!mp[s[i]].first) {
                mp[s[i]].first = ++k;
                a[mp[s[i]].second] = mp[s[i]].first + '0';
            }
            a += a[mp[s[i]].second];
            mp[s[i]].second = i;
        }

        return a;
    }
    bool isIsomorphic(string s, string t) {
        return (Process(s) == Process(t));
    }
};