class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // prefix sum & bit manipulation
        // hint: A ^ A = 0
        // hint: arr[l:r] = arr[0:(l-1)] ^ arr[0:r]
        vector<int> prefix(arr.begin(), arr.end());
        prefix.insert(prefix.begin(), 0);
        int len = prefix.size();
        
        for(int i=1; i<len; ++i) 
            prefix[i] ^= prefix[i - 1];

        int cnt = 0;
        for(int i=0; i<len; ++i) {
            for(int j=i+1; j<len; ++j) {
                if(prefix[i] == prefix[j]) cnt += j - i - 1;        
            }
        }

        return cnt;
    }
};