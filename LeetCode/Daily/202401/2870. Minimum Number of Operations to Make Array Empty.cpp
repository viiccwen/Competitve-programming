class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size() == 1) return -1;
        
        unordered_map<int, int> mp;
        int op_cnt = 0;
        
        for(auto i : nums) mp[i]++;
        
        for(auto [_, cnt] : mp) {
            int min_three = INT_MAX, min_two = INT_MAX;
            if(cnt == 1) return -1;
            else {
                if(cnt%3==0) min_three = min(min_three, cnt / 3);
                else min_three = min(min_three, cnt / 3 + 1);
                
                min_two = min(min_two, cnt / 2);
                op_cnt += min(min_three, min_two);
            } 
        }
        
        return op_cnt;
    }
};