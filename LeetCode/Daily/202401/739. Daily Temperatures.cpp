#define pii pair<int, int>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pii> sk;
        int n = temperatures.size();
        vector<int> answer(n, 0);

        sk.push( {n - 1, temperatures[n - 1]} );
        for(int i=n-2; i>=0; --i) {
            while(!sk.empty() && temperatures[i] >= sk.top().second) 
                sk.pop();
            

            if(!sk.empty()) 
                answer[i] = sk.top().first - i;
            

            sk.push( {i, temperatures[i]} );
        }

        return answer;
    }
};