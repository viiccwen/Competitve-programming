class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1_p = m - 1, n2_p = n - 1, n_end = m + n - 1;
        while (n2_p >= 0) {
            if (n1_p >= 0 && nums1[n1_p] >= nums2[n2_p]) {
                nums1[n_end--] = nums1[n1_p--];
            }
            else {
                nums1[n_end--] = nums2[n2_p--];
            }
        }
    }
};