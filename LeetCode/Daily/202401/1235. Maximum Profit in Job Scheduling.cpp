class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<tuple<int, int, int>> jobs(n);
        vector<int> dp(n + 1);

        for(int i=0; i<n; ++i) 
            jobs[i] = {endTime[i], startTime[i], profit[i]};

        sort(jobs.begin(), jobs.end());

        for(int i=0; i<n; ++i) {
            auto [end, start, pro] = jobs[i];

            int latestIdx = upper_bound(jobs.begin(), jobs.begin() + i, start, [&](int time, const auto& job) -> bool {
                return time < get<0>(job);
            }) - jobs.begin();

            dp[i + 1] = max(dp[i], dp[latestIdx] + pro);
        }

        return dp[n];
    }
};