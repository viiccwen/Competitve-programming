class Solution {
public:
    vector<string> ans;
    void recursion(string& s, vector<string>& dict, int index, string cur_s) {
        if(index == s.size()) {
            if(cur_s != "") ans.push_back(cur_s);
            return;
        }

        for(int i=index; i<s.size(); ++i) {
            string seg_s = s.substr(index, i - index + 1);

            if(find(dict.begin(), dict.end(), seg_s) != dict.end()) 
                recursion(s, dict, i + 1, (cur_s != "" ? cur_s + " " + seg_s : seg_s) );
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        recursion(s, wordDict, 0, "");
        return ans;
    }
};