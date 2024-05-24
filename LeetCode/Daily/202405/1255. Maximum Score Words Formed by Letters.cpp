class Solution {
public:
    int maximum = 0;

    bool canPick(vector<int>& freq, string& word, int value) {
        for(auto chr : word)
            if(--freq[chr - 'a'] < 0) return false;

        return true;
    }

    void recursion(vector<string>& words, vector<int> freq, vector<int>& score, int value, int index) {
        if(index == words.size()) {
            maximum = max(maximum, value);
            return;
        }

        // pick and not-pick:

        // not-pick
        recursion(words, freq, score, value, index + 1);
        
        // pick
        if(canPick(freq, words[index], value)) {
            for(auto chr : words[index]) value += score[chr - 'a'];
            recursion(words, freq, score, value, index + 1);
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0);
        for(auto e : letters) freq[e - 'a']++;

        recursion(words, freq, score, 0, 0);
        return maximum;
    }
};