class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> v_p(26), v_s(26), ans;
        int len_s = s.size(), len_p = p.size();
        int p_i = 0;

        for (char c : p) v_p[c - 'a']++;

        for (int s_i = 0; s_i < s.size(); s_i++) {
            v_s[s[s_i] - 'a']++;

            if (s_i - p_i + 1 == len_p && v_p == v_s) ans.push_back(p_i);

            if (s_i - p_i + 1 >= len_p) {
                v_s[s[p_i] - 'a']--;
                p_i++;
            }
        }

        return ans;
    }
};