/*264. Ugly Number II
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose 
prime factors only include 2, 3, 5. 

Example:
Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 
is the sequence of the first 10 ugly numbers.
Note:  
1 is typically treated as an ugly number.
n does not exceed 1690.

Hint:

The naive approach is to call isUgly 
for every number until you reach the nth one. 
Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.

An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.

The key is how to maintain the order of the ugly numbers. 
Try a similar approach of merging from three sorted lists: L1, L2, and L3.
Assume you have Uk, the kth ugly number. 
Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
*/
class UglyNum264
{
 public:
  int solve(int n) {
    std::vector<int> res(1, 1);
    int i2 = 0, i3 = 0, i5 = 0;
    while (res.size() < n) {
      int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
      int mn = std::min(m2, std::min(m3, m5));
      if (mn == m2) ++i2;
      if (mn == m3) ++i3;
      if (mn == m5) ++i5;
        res.push_back(mn);
    }
    return res.back();

  }

  void test() {
    int n = 10;
    std::cout << "n = " << n << ",  ugly number = " << solve(n) << std::endl;

  }


};
