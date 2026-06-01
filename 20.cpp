class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;
        unordered_map<char, char> brackets = {
            {')', '('}, {'}', '{'}, {']', '['}
        };

        for (const auto& c : s) {
            if (brackets.count(c)) {
                if (charStack.empty() || charStack.top() != brackets[c]) {
                    return false;
                }
                charStack.pop();
            } else {
                charStack.push(c);
            }
        }

        return charStack.empty();
    }
};

