/*Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary 
until the first non-whitespace character is found. Then, starting from this character, 
takes an optional initial plus or minus sign followed 
by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form 
the integral number, which are ignored and have no effect 
on the behavior of this function.

If the first sequence of non-whitespace characters in str 
is not a valid integral number, or if no such sequence exists 
because either str is empty or it contains only whitespace characters, 
no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store 
integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. 
If the numerical value is out of the range of representable values, 
INT_MAX (2^31 − 1) or INT_MIN (−2^31) is returned.

Example 1:
Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:
Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next 
character is not a numerical digit.

Example 4:
Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:
Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−2^31) is returned.*/

#include <limits.h>

class StrToInt8
{
public:
  int CharToInt(char c) {
     if (c == '0')
       return 0;
     else if (c == '1')
       return 1;
     else if (c == '2')
       return 2;
     else if (c == '3')
       return 3;
     else if (c == '4')
       return 4;
     else if (c == '5')
       return 5;
     else if (c == '6')
       return 6;
     else if (c == '7')
       return 7;
     else if (c == '8')
       return 8;
     else if (c == '9')
      return 9;
  }

	int solve(std::string str) {
    int i = 0;  int N = str.size();
    if (N == 0) return 0;
    while (i < N) {
      if (str[i] == ' ')
        i++;
      else 
        break;
    }
    if (i >= N) return 0;
    
    bool numSignNeg = false;
    if (str[i] == '-') {
      numSignNeg = true;
      i++;
    } else if (str[i] == '+') {
      numSignNeg = false;
      i++;
    } else if (str[i] >= '0' && str[i] <='9') {
      numSignNeg = false;
    } else {
      return 0;
    }

    std::vector<int> resVec;
    while (i < N) {
      if (str[i] >= '0' && str[i] <='9')
        resVec.push_back(CharToInt(str[i]));
      else 
        break;
      i++;
    }

    if (resVec.empty()) return 0;

    // summarize results
    double res = 0;
    for (int i=0; i<resVec.size(); ++i)
      res += resVec[i] * pow(10, (int)resVec.size()-i-1);

    if (numSignNeg)
      res *= -1;

    if (res < INT_MIN)
      return INT_MIN;
    else if (res > INT_MAX)
      return INT_MAX;
    else 
      return int(res);
    
	}


  void test()
  {

    std::string strIn = "   -42";
    std::cout << "input str : " << strIn << ",   output number :" << solve(strIn) << std::endl;
    strIn = "4193 with words";
    std::cout << "input str : " << strIn << ",   output number :" << solve(strIn) << std::endl;
    strIn = "words and 987";
    std::cout << "input str : " << strIn << ",   output number :" << solve(strIn) << std::endl;
    strIn = "-91283472332";
    std::cout << "input str : " << strIn << ",   output number :" << solve(strIn) << std::endl;

  }




	
};
