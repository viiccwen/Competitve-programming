class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k == 1) return max(arr[0], arr[1]);
        if(k >= arr.size()) return *max_element(arr.begin(), arr.end());

        int cur_win = arr[0];
        int cons_win = 0;

        for(int i=1;i<arr.size();i++) {
            if(cur_win > arr[i]) cons_win++;
            else {
                cur_win = arr[i];
                cons_win = 1;
            }

            if(cons_win == k) return cur_win;
        }

        return cur_win;
    }
};