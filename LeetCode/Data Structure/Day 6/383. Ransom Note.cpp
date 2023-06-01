class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for (char i : magazine) mp[i]++;
        for (char i : ransomNote) mp[i]--;
        for (auto i : mp) if (i.second < 0) return false;
        return true;
    }
};