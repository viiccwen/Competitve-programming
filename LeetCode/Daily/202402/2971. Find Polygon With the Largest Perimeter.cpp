#define ll long long
class Solution {
public:
    ll largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        ll sum = 0;
        sort(nums.begin(), nums.end());
        
        for(auto i : nums) sum += i;
        
        for(int i=n-1; i>=2; --i) {
            sum -= nums[i];
            if(sum > nums[i]) return sum + nums[i];
        }
        return -1;
    }
};