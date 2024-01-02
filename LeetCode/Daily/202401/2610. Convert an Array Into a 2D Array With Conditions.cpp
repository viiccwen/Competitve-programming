class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        int max_cnt = 0;
        for(auto ite : nums) {
            mp[ite]++;
            max_cnt = max(max_cnt, mp[ite]);
        }

        vector<vector<int>> ans;
        for(int i=0; i<max_cnt; ++i) {
            vector<int> tmp;
            for(auto &[key, val] : mp) {
                if(val != 0) {
                    tmp.push_back(key);
                    val--;
                }
            }
            ans.push_back(tmp);
        }

        return ans;
    }
};