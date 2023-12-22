class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> left(n), right(n);
        
        for(int i=0, j=n-i-1;i<n;i++, j--) {
            left[i] = (i-1 >= 0) ? left[i-1] : 0;
            right[j] = (j+1 < n) ? right[j+1] : 0;
            if(s[i] == '0') left[i] = (i-1 >= 0) ? left[i]+1 : 1;
            if(s[j] == '1') right[j] = (j+1 < n) ? right[j]+1 : 1;
        }

        int maxx = 0;
        for(int i=0;i<n-1;i++) maxx = max(maxx, left[i] + right[i+1]);
        

        return maxx;
    }
};