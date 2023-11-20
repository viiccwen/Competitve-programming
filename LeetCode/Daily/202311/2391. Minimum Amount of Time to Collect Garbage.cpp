class Solution {
public:
    int travelAround(vector<string>& garbage, vector<int>& travel, vector<pair<int, int>>& vec) {
        int now_des = 0;
        int sum = 0;
        for (auto [key, val] : vec) {
            if (key != now_des) {
                for (int i = now_des; i < key; i++) sum += travel[i];
                now_des = key;
            }
            sum += val;
        }
        return sum;
    }
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<pair<int, int>> G, P, M;

        for (int i = 0; i < garbage.size(); i++) {
            int curG = 0, curP = 0, curM = 0;
            for (int j = 0; j < garbage[i].size(); j++) {
                if (garbage[i][j] == 'G') curG++;
                else if (garbage[i][j] == 'P') curP++;
                else curM++;
            }
            if (curG) G.push_back({ i, curG });
            if (curP) P.push_back({ i, curP });
            if (curM) M.push_back({ i, curM });
        }

        int sum = 0;
        sum += travelAround(garbage, travel, G);
        sum += travelAround(garbage, travel, P);
        sum += travelAround(garbage, travel, M);

        return sum;
    }
};