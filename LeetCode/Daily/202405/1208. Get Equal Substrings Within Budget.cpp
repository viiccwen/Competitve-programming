class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> diff(s.size());

        for(int i=0; i<s.size(); ++i) diff[i] = abs(s[i] - t[i]);

        // sliding window
        int l = 0, r = 0, cur = 0, maximum = 0;
        while(r < s.size()) {
            cur += diff[r];

            while(cur > maxCost) 
                cur -= diff[l++];
            
            maximum = max(maximum, r - l + 1);
            r++;
        }

        return maximum;
    }
};