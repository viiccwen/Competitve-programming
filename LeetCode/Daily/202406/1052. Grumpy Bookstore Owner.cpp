class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int interval = 0, max_interval = 0;
        int sum = 0;
        int l = 0, r = 0;
        int len = customers.size();

        while(r < minutes) {
            if(grumpy[r]) interval += customers[r];
            else sum += customers[r];
            r++;
            max_interval = max(max_interval, interval);
        }

        while(r < len) {
            if(grumpy[r]) interval += customers[r];
            else sum += customers[r];
            if(grumpy[l]) interval -= customers[l];
            l++, r++;
            max_interval = max(max_interval, interval);
        }

        return sum + max_interval;
    }
};