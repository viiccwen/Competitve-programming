class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> alpha(26, -1);
        int n = s.size();

        for(int i=0; i<n; ++i){
            if(alpha[s[i] - 'a'] == -1) alpha[s[i] - 'a'] = i;
            else alpha[s[i] - 'a'] = -2;
        } 

        int firstAppear = INT_MAX;
        for(int i=0; i<26; ++i)
            if(alpha[i] >= 0) firstAppear = min(firstAppear, alpha[i]);
        
        return firstAppear == INT_MAX ? -1 : firstAppear; 
    }
};