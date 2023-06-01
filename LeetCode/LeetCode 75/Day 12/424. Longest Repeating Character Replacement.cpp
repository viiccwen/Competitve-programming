class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> v(128);
        int len = s.size();
        int begin = 0, largestCnt = 0;

        for (int end = 0; end < len; end++) {
            largestCnt = max(largestCnt, ++v[s[end]]);

            if (end - begin + 1 - largestCnt > k) v[s[begin++]]--;
        }

        return len - begin;
    }
};