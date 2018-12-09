/*150. Evaluate Reverse Polish Notation
Evaluate the value of an arithmetic expression in Reverse Polish 
Notation.

Valid operators are +, -, *, /. Each operand may be an integer or 
another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression 
would always evaluate to a result and there won't be any divide by zero 
operation.

Example 1:
Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:
Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:
Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/


class EvalRPN150 {

public:
  bool isOp(string const & str) {
    return (str == "+" || str == "-" || str =="*" || str == "/");
  }
  int eval(int l, int r, string const & op) {
    if (op == "+")
      return l + r;
    else if (op == "-")
      return l - r;
    else if (op == "*")
      return l * r;
    else if (op == "/")
      return l/r;
  }

  // just use stack
  int solve(vector<string>& tokens) {
    stack<int> stk;

    for (string str : tokens) {
        if (!isOp(str)) {
          stk.push(stoi(str));
        }  else {
          int r = stk.top(); stk.pop();
          int l = stk.top(); stk.pop();
          stk.push(eval(l,r,str));
        }

    }

    return stk.top();
  }


  void test()
  {
     vector<string> tokens;
     tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
     cout << "input token : ";
     print_data(tokens);
     cout << "res = " << solve(tokens) << endl;

  }

};
