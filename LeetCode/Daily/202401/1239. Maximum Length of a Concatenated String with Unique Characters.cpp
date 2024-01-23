class Solution {
public:
    int dfs(int idx, vector<string>& arr, vector<int> visited) {
        if(idx == arr.size()) return 0;

        int skip = dfs(idx + 1, arr, visited);

        for(char c : arr[idx]) {
            if(visited[c - 'a']) return skip;
            visited[c - 'a'] = 1;
        }
        int nonskip = arr[idx].size() + dfs(idx + 1, arr, visited);

        return max(skip, nonskip);
    }
    int maxLength(vector<string>& arr) {
        vector<int> visited(26, 0);
        return dfs(0, arr, visited);
    }
};