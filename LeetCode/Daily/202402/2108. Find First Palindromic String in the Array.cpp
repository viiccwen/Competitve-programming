class Solution {
public:
    bool isPalindrome(string& str) {
        int n = str.size();
        for(int i=0, j=n-1; i<j; i++, j--) 
            if(str[i] != str[j]) return false;

        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int n = words.size();

        for(int i=0; i<n; ++i) 
            if(isPalindrome(words[i])) return words[i];   
        
        return "";
    }
};