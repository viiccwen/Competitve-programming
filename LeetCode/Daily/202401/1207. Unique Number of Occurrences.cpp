class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        unordered_set<int, int> freq;

        for(int i : arr) mp[i]++;

        for(auto [_, val] : mp) 
            if(++freq[val] > 1) return false;
        
        return true;
    }
};