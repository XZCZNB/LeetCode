//给定一个只包括'('，')'，'{'，'}'，'['，']'的字符串s，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//每个右括号都有一个对应的相同类型的左括号

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        char cur = 0;
        for(auto i : s) {
            if(i == '(' || i == '{' || i == '[') {
                stk.push(i);
            }
            else {
                if (stk.empty()) return false;
                cur = stk.top();
                if((i == ')' && cur == '(') || (i == '}' && cur == '{') || (i == ']' && cur == '[')) {
                    stk.pop();
                }
                else return false;
            }
        }
        return stk.empty();
    }
};