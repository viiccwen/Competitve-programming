class Solution {
public:
    int longestPalindrome(string s) {
        int len = s.size();
        if (len == 1) return 1;

        unordered_map<char, int> mp;
        int ans = 0;
        for (int i = 0; i < len; i++)
            mp[s[i]]++;

        for (auto i : mp) {
            ans += i.second / 2 * 2;
            if (!(ans % 2) && (i.second % 2))
                ans++;
        }

        return ans;
    }
};