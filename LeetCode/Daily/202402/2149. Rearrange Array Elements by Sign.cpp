class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(n / 2), neg(n / 2);
        vector<int> res(n);

        int pi = 0, ni = 0;
        for(auto ele : nums) {
            if(ele > 0) pos[pi++] = ele;
            else neg[ni++] = ele;
        }

        pi = ni = 0;
        for(int i=0;i<n;i++) {
            if(i % 2 == 0) res[i] = pos[pi++];
            else res[i] = neg[ni++];
        }

        return res;
    }
};