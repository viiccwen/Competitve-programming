class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;
        vector<pair<int, int>> vec;
        for(int i=0; i<n; ++i) 
            mp[arr[i]]++;

        for(auto [key, val] : mp) {
            vec.emplace_back(key, val);
        }

        sort(vec.begin(), vec.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        });

        for(int i=0;i<vec.size();i++) {
            if(k >= vec[i].second) k -= vec[i].second;
            else return vec.size() - i; 
        }

        return 0;
    }
};