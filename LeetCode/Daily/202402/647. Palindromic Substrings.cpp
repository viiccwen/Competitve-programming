class Solution {
public:
    void isPalindrome(string& s, int start, int end, int& n, int& cnt) {
        while(start >= 0 && end < n) {
            if(s[start--] == s[end++]) cnt++;
            else break;
        }
    }
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;

        for(int i=0; i<n; i++) {
            isPalindrome(s, i, i, n, cnt);   
            isPalindrome(s, i, i + 1, n, cnt);   
        } 

        return cnt;
    }
};