class Solution {
public:
    string Process(const string& s, int& i) {
        string str;
        while (i < s.size() && s[i] != ']') {
            if (!isdigit(s[i])) {
                str += s[i++];
            }
            else {
                int n = 0;
                while (i < s.size() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';

                i++;
                string temp = Process(s, i);
                i++;

                while (n-- > 0) str += temp;
            }
        }
        return str;
    }
    string decodeString(string s) {
        int i = 0;
        return Process(s, i);
    }
};