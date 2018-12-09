/*Given an integer n, count the total number of digit 1 appearing 
in all non-negative integers less than or equal to n.

Example:
Input: 13
Output: 6 
Explanation: Digit 1 occurred in the following numbers: 
1, 10, 11, 12, 13.*/


class NumOfDigitOne233
{
public:
  // convert integer into vector of digits, start with low digits
  std::vector<int> convNumToVec(int n) {
    std::vector<int> vecRev;
    int residual = n;
    while (residual > 0) {
      vecRev.push_back(residual%10);
      residual = residual/10;
    }
    return vecRev;
  }

  // convert vector of digits(start with low digits) into integer
  int convVecToNum(std::vector<int> const & vec) {
    int res = 0;
    int digitBase = 1;
    for (int i=0; i<vec.size(); ++i) {
      res += digitBase * vec[i];
      digitBase *= 10;
    }
    return res;
  }


   
  int solve(int n) {
    std::vector<int> vecRev = convNumToVec(n);

    int count = 0;
    // from low to high, loop over all the digits, the idea is that
    // we compare the current digit value to 1(at current digit, we will make a 1),
    //and determine the possible combination of remaining digits.
    for (int i=0; i<vecRev.size(); ++i) {
       std::vector<int> higherDigits(vecRev.begin()+i+1, vecRev.end());
       std::vector<int> lowerDigits(vecRev.begin(), vecRev.begin()+i);
      if (vecRev[i] == 0) { 
        // curr digit smaller than 1, so the high remaining
        // digits can only decrease, and the low remaining digits can be anything
        int numHigherDigits = convVecToNum(higherDigits); 
        int numLowDigits = pow(10,lowerDigits.size());
        count += numHigherDigits * numLowDigits;

      } else if (vecRev[i] > 1) {
        // curr digit smaller than 1, so the high remaining
        // digits can be the same or decrease, and the low remaining digits can be anything
        int numHigherDigits = convVecToNum(higherDigits) + 1;
        int numLowDigits = pow(10,lowerDigits.size());
        count += numHigherDigits * numLowDigits;
      } else {
        // curr digit equal to 1, so if high remaining digits the same, low
        // remaining digits can only be same or smaller,  if high remaining digits decrease,
        // low remaining digits can be anything
        int numLowDigits = convVecToNum(lowerDigits);
        count += numLowDigits + 1;  // the case when high remaining digits the same
        count += convVecToNum(higherDigits) * pow(10, lowerDigits.size()); // the case when high remaining digits decrease
      }
      std::cout << "count = " << count << std::endl;

    }
    return count;
  }


  void test() {
    int n = 13;
    std::cout << "intput num is : " << n << ", " << "number of digits 1 is :" << solve(n) << std::endl;
    n = 100;
    std::cout << "intput num is : " << n << ", " << "number of digits 1 is :" << solve(n) << std::endl;



  }
 
        



};
