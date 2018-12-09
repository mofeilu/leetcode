/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:
-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]*/

class pow50
{
   /// note: to make code efficient, we solve 
   /// recursively by cutting in half of n   
   double solve(double x, int n) {
   	  if (n == 0) return 1;

   	  double half = solve(x, n/2);
      double res = half*half;
   	  if (n%2 == 1) res *= x;
   	  else if (n%2==-1) res /= x;
      return res;

   }


   void test()
   {
     double x, n;
     x = 2; n = 10;
     std::cout << "x, n, pow(x,n) = " << x << ' ' << n << solve(x,n) << std::endl;
     x = 2.00000; n =  -2;
     std::cout << "x, n, pow(x,n) = " << x << ' ' << n << solve(x,n) << std::endl;



   }




};
