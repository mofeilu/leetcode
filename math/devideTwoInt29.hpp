/*Given two integers dividend and divisor, 
divide two integers without using multiplication, 
division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:
Input: dividend = 10, divisor = 3
Output: 3


Example 2:
Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which 
could only store integers within the 32-bit signed integer range: 
[−2^31,  2^31 − 1]. For the purpose of this problem, 
assume that your function returns 2^31 − 1 when the 
division result overflows.*/

#include <limits.h>

class devideTwoInt29
{

  public:
    /// assume input a and b are all positive int
    int dividePosInt(int a, int b) {
       int r = 0;
       // this is simply too slow 
      while (a >= b) {
        a -= b;
        r++;
      }
      return r;
    }

    /// assume input a and b are all positive int
    /// we increase divisor 2 times each round to approach the dividend
    /// in this way we speed up the calculaiton
    int dividePosIntFast(int a, int b) {
      if (a < b)  // termination condition
        return 0;

      int r = 0; // result
      int res = 0; //residual

      int curr_b  = b; // current b
      while (curr_b <= a && curr_b > 0) {  // make sure curr_b does not overflow
        res = a - curr_b;
        r = (r==0) ? 1 : r + r;
        curr_b = curr_b + curr_b;
      }

      return r +  dividePosIntFast(res, b);
      
    }


  	int solve(int dividend, int divisor) {
      // handle special case, because we are going to reverse the sign of neg number
      if (divisor == INT_MIN)
        return (dividend == INT_MIN) ? 1 : 0;

      int res = 0;
      if (dividend == INT_MIN) { // 
        if (divisor == -1) // will overflow
          return INT_MAX;

        dividend += abs(divisor); // here divisor would not be INT_MIN 
        res++;
      }

      bool isNotNeg = (dividend >= 0 && divisor >= 0) || (dividend <= 0 && divisor <= 0);
      if (dividend < 0)
      	dividend = - dividend;
      if (divisor < 0)
       	divisor = - divisor;

      res += dividePosIntFast(dividend, divisor);
     
      return isNotNeg ? res : - res;
  	}


  	void test() {

      int a, b;
      a = 10; b = 3;
      std::cout << "a, b, res = " << a << ' ' << b << ' ' << solve(a,b) << std::endl;
      a = 7; b = -3;
      std::cout << "a, b, res = " << a << ' ' << b << ' ' << solve(a,b) << std::endl;


  	}



};
