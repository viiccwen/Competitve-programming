class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        stack<char> sk;

        if (len == 1) return false;

        for (auto chr : s) {
            if (chr == '(' || chr == '{' || chr == '[') sk.push(chr);
            else if (!sk.empty()) {
                if (sk.top() == '(' && chr == ')') sk.pop();
                else if (sk.top() == '[' && chr == ']') sk.pop();
                else if (sk.top() == '{' && chr == '}') sk.pop();
                else return false;
            }
            else return false;
        }

        if (!sk.empty()) return false;
        else return true;
    }
};