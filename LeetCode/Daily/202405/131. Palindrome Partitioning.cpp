class Solution {
public:
    int n;
    vector<vector<int>> memo;
    vector<vector<string>> ans;
    bool isPalindrome(string& s, int l, int r) {
        if(memo[l][r] != -1) return memo[l][r] == 1;

        while(l < r) {
            if(s[l] != s[r]) return memo[l][r] = 0;
            l++, r--;
        }

        return memo[l][r] = 1;
    }
    void Helper(vector<string> valid, string& s, int start) {
        if(start >= n) ans.push_back(valid);

        for(int end=start;end<n;++end) {
            if(isPalindrome(s, start, end)) {
                valid.push_back(s.substr(start, end - start + 1));
                Helper(valid, s, end + 1);
                valid.pop_back(); // backtracking
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        if(n == 1) return {{ s }};
        memo.assign(n, vector<int>(n, -1));
        Helper({}, s, 0);
        return ans;
    }
};