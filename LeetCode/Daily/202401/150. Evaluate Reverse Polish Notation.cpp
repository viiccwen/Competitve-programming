class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sk;

        for(auto str : tokens) {
            if(str == "+" || str == "-" || str == "*" || str == "/") {
                int b = sk.top(); sk.pop();
                int a = sk.top(); sk.pop();

                if(str == "+") sk.push(a + b);
                else if(str == "-") sk.push(a - b);
                else if(str == "*") sk.push(a * b);
                else if(str == "/") sk.push(a / b);
            
            } else sk.push(stoi(str));
        }

        return sk.top();
    }
};