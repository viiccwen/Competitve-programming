class Solution {
 public:
  string sortVowels(string s) {
    string t = s;
    vector<int> vowel_idx;
    vector<char> vowel;
    int n = s.size();

    for (int i = 0; i < n; i++) {
      if (t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' ||
          t[i] == 'u' || t[i] == 'A' || t[i] == 'E' || t[i] == 'I' ||
          t[i] == 'O' || t[i] == 'U') {
        vowel_idx.emplace_back(i);
        vowel.emplace_back(t[i]);
      }
    }

    sort(vowel.begin(), vowel.end());

    for (int i = 0, k = 0; i < vowel_idx.size(); i++) {
      t[vowel_idx[i]] = vowel[k++];
    }

    return t;
  }
};