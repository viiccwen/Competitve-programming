class Solution {
public:
    string ToString(int a) {
        stringstream ss;
        ss << a;
        string str = ss.str();

        return str;
    }
    string getHint(string secret, string guess) {
        string str_a = "0", str_b = "0";
        int len = secret.size();
        unordered_map<char, int> mp;
        int a = 0, b = 0;

        if (secret == guess) {
            str_a = len + '0';
            return str_a + "A" + str_b + "B";
        }

        for (int i = 0; i < len; i++) {
            if (secret[i] == guess[i]) {
                a++;
                secret[i] = guess[i] = 'x';
            }
            if (secret[i] != 'x')
                mp[secret[i]]++;
        }

        for (int i = 0; i < len; i++) {
            if (mp[guess[i]] > 0) {
                mp[guess[i]]--;
                b++;
            }
        }

        str_a = ToString(a);
        str_b = ToString(b);

        return str_a + "A" + str_b + "B";
    }
};