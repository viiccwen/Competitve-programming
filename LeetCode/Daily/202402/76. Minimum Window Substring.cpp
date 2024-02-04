class Solution {
public:
    string minWindow(string s, string t) {
        int s_len = s.size(), t_len = t.size();
        if(s_len < t_len) return "";

        vector<int> alpha(150, 0);
        int cnt = t_len;
        int l = 0, r = 0, minn = INT_MAX, start_idx = 0;

        for(auto c : t) alpha[c]++;

        while(r < s_len) {
            if(alpha[ s[r++] ]-- > 0) cnt--;

            while(cnt == 0) {
                if(r - l < minn) {
                    start_idx = l;
                    minn = r - l;
                }

                if(alpha[ s[l++] ]++ == 0) cnt++;
            }
        }

        return minn == INT_MAX ? "" : s.substr(start_idx, minn);
    }
};