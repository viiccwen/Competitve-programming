class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.size();
        if (len == 1) return 0;

        unordered_map<char, int> mp;
        int first = -1e9, ans = 1e9;
        for (int i = 0; i < len; i++) {
            if (!mp.count(s[i]))
                mp[s[i]] = i;
            else if (mp[s[i]] != -1)
                mp[s[i]] = -1;
        }

        for (auto j : mp) {
            if (j.second != -1)
                ans = min(ans, j.second);
        }

        if (ans == 1e9) return -1;
        else return ans;
    }
};