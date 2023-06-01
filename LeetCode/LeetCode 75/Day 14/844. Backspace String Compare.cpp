class Solution {
public:
    string ToString(deque<char>& dq) {
        string str;

        while (!dq.empty()) {
            str += dq.front();
            dq.pop_front();
        }

        return str;
    }
    bool backspaceCompare(string s, string t) {
        deque<char> dq;
        string ns, nt;
        int len_s = s.size(), len_t = t.size();

        for (int i = 0; i < len_s; i++) {
            if (s[i] != '#') dq.push_back(s[i]);

            else if (!dq.empty()) dq.pop_back();
        }

        ns = ToString(dq);

        for (int i = 0; i < len_t; i++) {
            if (t[i] != '#') dq.push_back(t[i]);

            else if (!dq.empty()) dq.pop_back();
        }

        nt = ToString(dq);

        if (ns == nt) return true;
        else return false;
    }
};