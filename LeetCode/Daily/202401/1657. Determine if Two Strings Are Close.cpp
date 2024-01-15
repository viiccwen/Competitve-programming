class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        if(len1 != len2) return false;

        vector<int> q1(26, 0);
        vector<int> q2(26, 0);

        for(auto c : word1) q1[c - 'a']++;
        for(auto c : word2) q2[c - 'a']++;

        for(int i=0; i<26; ++i) 
            if((q1[i] == 0 && q2[i] != 0) || (q1[i] != 0 && q2[i] == 0))
                return false;
        

        sort(q1.begin(), q1.end());
        sort(q2.begin(), q2.end());

        for(int i=0; i<26; ++i)
            if(q1[i] != q2[i]) return false;
        

        return true;
    }
};