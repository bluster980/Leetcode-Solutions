class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;

        static unordered_map<string, function<long long(long long, long long)>> ops =
        {
            {"+", [](auto x, auto y){return x + y;}},
            {"-", [](auto x, auto y){return x - y;}},
            {"*", [](auto x, auto y){return x * y;}},
            {"/", [](auto x, auto y){return x / y;}},
        };

        for (auto & t: tokens)
        {
            if (ops.find(t) != ops.end())
            {
                long long y = s.top(); s.pop();
                long long x = s.top(); s.pop();
                const auto op = ops[t];
                long long res = op(x, y);
                s.push(res);
            }
            else
            {
                int val = std::stoi(t);
                s.push(val);
            }
        }
        return s.top();
    }
};