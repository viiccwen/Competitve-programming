class Solution {
public:
    int _reverse(int num) {
        string str = to_string(num);
        reverse(str.begin(), str.end());
        return stoi(str);
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        long int sum = 0;
        const int MOD = 1e9 + 7;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] - _reverse(nums[i]);
            mp[nums[i]]++;
        }

        for (auto [_, val] : mp) {
            if (val >= 2) {
                long int k = val - 1;
                long int s = k * (k + 1) / 2;
                sum += s;
                sum %= MOD;
            }
        }

        return static_cast<int>(sum);
    }
};
//nums[i] + rev(nums[j]) == nums[j] + rev(nums[i]
//nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])

// an = a1 + (n-1)*d
// a3 = 3 + -2 = 1
// s = n(a1 + an) / 2