class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> min_alpha(26, INT_MAX);
        for(auto &word : words) {
            vector<int> alpha(26, 0);
            for(char &c : word) alpha[c - 'a']++;
            for(int i=0; i<26; ++i) min_alpha[i] = min(min_alpha[i], alpha[i]);
        }

        vector<string> ans;
        for(int i=0; i<26; ++i) {
            string k;
            for(int j=0; j<min_alpha[i]; ++j) {
                k = (i + 'a');
                ans.push_back(k);
            }
        }

        return ans;
    }
};