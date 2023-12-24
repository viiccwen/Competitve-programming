class Solution {
public:
    int minOperations(string s) {
        int cntzero = 0, cntone = 0;
        for(int i=0;i<s.size();i++) {
            if(i % 2 == 0) {
                if(s[i] == '0') cntone++;
                else cntzero++;
            } else {
                if(s[i] == '0') cntzero++;
                else cntone++;
            }
        }

        return min(cntzero, cntone);
    }
};