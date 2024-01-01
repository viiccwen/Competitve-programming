class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size() == 0) return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0;

        int sIdx = s.size() - 1;
        int gIdx = g.size() - 1;
        while(sIdx >= 0 && gIdx >= 0) {
            if(s[sIdx] >= g[gIdx]) {
                cnt++;
                sIdx--;
            }
            gIdx--;
        }

        return cnt;
    }
};