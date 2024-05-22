class Solution {
public:
    vector<vector<int>> ans;
    void recursive(vector<int>& nums, unordered_set<int> ust, int idx) {
        if(idx == nums.size()) {
            vector<int> cur_ans;
            for(auto ele : ust) cur_ans.push_back(ele);
            ans.push_back(cur_ans);
            return;
        }

        recursive(nums, ust, idx + 1);
        ust.insert(nums[idx]);
        recursive(nums, ust, idx + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        recursive(nums, {}, 0);
        return ans;
    }
};