class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> sk;

        for(int i=0; i<n; ++i) {
            while(!sk.empty() && arr[sk.top()] >= arr[i]) sk.pop();
            if(!sk.empty()) left[i] = sk.top();
            sk.push(i);
        }

        sk = stack<int>();

        for(int i=n-1; i>=0; --i) {
            while(!sk.empty() && arr[sk.top()] > arr[i]) sk.pop();
            if(!sk.empty()) right[i] = sk.top();
            sk.push(i);
        }

        long long ans = 0;

        for(int i=0; i<n; ++i) {
            ans += static_cast<long long>(i - left[i]) * (right[i] - i) * arr[i] % MOD;
            ans %= MOD;
        }

        return ans;
    }
};