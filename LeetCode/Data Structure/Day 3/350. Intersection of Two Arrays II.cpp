class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> mp;
        int len1 = nums1.size(), len2 = nums2.size();

        for (int i = 0; i < len1; i++) {
            if (!mp[nums1[i]])
                mp[nums1[i]] = 1;
            else
                mp[nums1[i]]++;
        }

        for (int i = 0; i < len2; i++) {
            if (mp[nums2[i]]) {
                mp[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }

        return ans;
    }
};