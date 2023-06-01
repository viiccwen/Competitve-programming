class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0, right = len - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;

            if (target > nums[mid]) left = mid + 1;
            else if (target < nums[mid]) right = mid - 1;
            else return mid;
        }

        return -1;
    }
};