class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> st{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        int n = s.size();
        int first = 0, second = 0;
        for(int i=0; i<n/2; ++i) {
            if(st.find(s[i]) != st.end()) first++;
            if(st.find(s[n-i-1]) != st.end()) second++;
        }

        return (first == second);
    }
};