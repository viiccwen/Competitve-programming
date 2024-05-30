class Solution {
public:
    int numSteps(string s) {
        int len = s.size();

        int ans = 0, carry = 0;
        for(int i=len-1; i>0; --i) {
            if( ((s[i] - '0') + carry) % 2 == 0) ans++;
            else {
                ans += 2;
                carry = 1;
            }
        }

        return ans + carry;
    }
};