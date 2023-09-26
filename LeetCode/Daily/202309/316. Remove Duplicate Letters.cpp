class Solution {
 public:
  string removeDuplicateLetters(string s) {
    vector<int> lastIndex(26, 0);
    vector<bool> visited(26, false);
    stack<char> st;

    for (int i = 0; i < s.size(); i++) lastIndex[s[i] - 'a'] = i;

    for (int i = 0; i < s.size(); i++) {
      int cur = s[i] - 'a';

      if (visited[cur]) continue;

      while (st.size() > 0 && st.top() > s[i] &&
             i < lastIndex[st.top() - 'a']) {
        visited[st.top() - 'a'] = false;
        st.pop();
      }

      st.push(s[i]);
      visited[cur] = true;
    }

    string ans = "";
    while (!st.empty()) {
      ans = st.top() + ans;
      st.pop();
    }

    return ans;
  }
};