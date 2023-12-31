class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        int maxx = -1;

        for(int i=0; i<n; ++i) {
            if(mp.find(s[i]) != mp.end())
                maxx = max(maxx, i - mp[s[i]] - 1);
            else 
                mp[s[i]] = i;
        }

        return maxx;
    }
};