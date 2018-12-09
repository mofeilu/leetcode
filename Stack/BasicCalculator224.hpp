/*224. Basic Calculator

Implement a basic calculator to evaluate a simple 
expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:
Input: "1 + 1"
Output: 2
Example 2:

Input: " 2-1 + 2 "
Output: 3
Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/
class BasicCalculator224 {

public:
  /* idea: we use two stacks: one for numbers, one for operators +, -,(, ).  the rule is : whenever the operator 
  stack meet a ')', pop the stack of operator until a '(' is reached, at meantime, combine operator and numbers to evaluate, and push back to number stack.

  here's a trick, to respect the left to right order like 2 - 1 +  2
  we need to read expression from right to left, so that 2 -1 is evaluated first(because stack pop last in)
  */
  int getNum(string & str, int endPos, int & size) {
    int i = endPos;
    while (i >=0  && isdigit(str[i])) --i;
    size = endPos - i;
    return stoi(str.substr(i+1,size));
  }

  int eval(int l, int r, char op) {
    return (op == '+') ? l + r : l - r ;
  }

  int solve(string s) {
    stack<int> nums;
    stack<char> ops;
    // fill the stacks
    int i = s.size()-1;
    while (i >= 0) {
      if (isdigit(s[i])) {
        int size;
        nums.push(getNum(s, i, size));
        i -= size;
      } else if (s[i] == '+' || s[i] == '-' || s[i] == ')') {
        ops.push(s[i]);
        --i;
      } else if (s[i] == '(') {  // time to evaluate
        while (ops.top() != ')') {
          int l = nums.top(); nums.pop();
          int r = nums.top(); nums.pop();
          nums.push(eval(l,r,ops.top())); 
          ops.pop();
        }
        // now we have '(', just pop
        ops.pop();

        --i;
      } else { // must be space or tab, etc
        --i;
      }
    }

    // clean the remaining stack elems
    // we only have '+', '-' in ops 
    while (!ops.empty()) {
      int l = nums.top(); nums.pop();
      int r = nums.top(); nums.pop();
      nums.push(eval(l,r,ops.top())); 
      ops.pop();
    }

    // the final res is in nums stack
    return nums.top();
  }


  void test()
  {
    vector<string> exprs = 
    {"1 + 1", "2-1 + 2 ", "(1+(4+5+2)-3)+(6+8)"};
    for (string s : exprs) {
      cout << "input expression : " << s << endl;
      cout << "res = " << solve(s) << endl;
    }

  }

};
