class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, long> mp;
        int len = arr.size();
        int MOD = 1e9 + 7;
        long ans = 0;

        for(int num : arr) {
            long ways = 1;

            for(int j=0, left=arr[0] ;left<=sqrt(num); left=arr[++j]) {
                if(num % left != 0) continue;
                
                int right = num / left;
                
                if(mp.find(right) != mp.end()) 
                    ways = (ways + mp[left] * mp[right] * (left == right ? 1 : 2)) % MOD;
            }
            mp[num] = ways;
            ans = (ans + ways) % MOD;
        }

        return (int)ans;
    }
};