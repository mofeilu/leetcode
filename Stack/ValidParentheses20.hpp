/*20. Valid Parentheses

Given a string containing just the characters 
'(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true
*/

class ValidParentheses20 {

public:
  // idea is simple, use a stack
  bool solve(string s) {
    stack<int> stk;
    for (char x : s) {
      if (x == '{' || x == '[' || x == '(') {
        stk.push(x);
      } else {
        if (stk.empty()) return false;
        if (x == '}') {
          if (stk.top() != '{') return false;
          stk.pop();
        } else if (x == ')') {
          if (stk.top() != '(') return false;
          stk.pop();
        } else if (x == ']') {
          if (stk.top() != '[') return false;
          stk.pop();
        }
      }
    }

    if (!stk.empty()) return false;
    return true;
  }

  void test()
  {
    vector<string> strs = {"()","()[]{}", "(]", "([)]","{[]}"};
    for (int i=0; i<strs.size(); ++i) 
      cout << strs[i] << (solve(strs[i]) ?  " is " : " is not ") << "valid \n";
  }

};
