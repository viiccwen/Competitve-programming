class Solution {
 public:
  void dfs(unordered_map<string, vector<string>>& mp, vector<string>& vec,
           string target) {
    while (!mp[target].empty()) {
      string next = mp[target].back();
      mp[target].pop_back();
      dfs(mp, vec, next);
    }
    vec.push_back(target);
  }
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string, vector<string>> mp;
    vector<string> vec;

    for (auto ticket : tickets) mp[ticket[0]].push_back(ticket[1]);

    for (auto& [_, des] : mp) sort(des.rbegin(), des.rend());

    dfs(mp, vec, "JFK");
    reverse(vec.begin(), vec.end());

    return vec;
  }
};