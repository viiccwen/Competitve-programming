class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;

        for(int x : nums) {
            if(sub.empty() || sub[sub.size() - 1] < x)
                sub.push_back(x);
            else {
                auto ite = lower_bound(sub.begin(), sub.end(), x);
                *ite = x;
            }
        }

        return sub.size();
    }
};