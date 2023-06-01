class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map <int, int> map;
        bool flag = false;

        for (int i = 0; i < nums.size(); i++) {
            if (!map[nums[i]])
                map[nums[i]] = 1;
            else {
                flag = true;
                break;
            }
        }

        return flag;
    }
};