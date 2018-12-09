/*Given two non-negative integers num1 and num2 represented as strings, 
return the product of num1 and num2, also represented as a string.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/


class MultStr43
{
public:

  std::string reverseStr(std::string strIn) {
    std::string strOut(strIn.size(),'0');
    for (int i=0; i<strIn.size(); ++i)
      strOut[i] = strIn[strIn.size()-i-1];
    return strOut;
  }

  // the idea is to do the multipy the way we do it mannually, need to reverse the string to start
  // from low digit to high digit
  std::string solve(std::string num1, std::string num2) {
    std::string num1Rev = reverseStr(num1);
    std::string num2Rev = reverseStr(num2);
    int n1 = num1.size();
    int n2 = num2.size();

    // length of result of a*b is at most the sum of a and b's length
    std::string res(n1+n2,'0'); // result is reversed

    int carry = 0;
    int val = 0;

    // we now calculate a*b mannually
    for (int j=0; j<n2; ++j) {  // b
      carry = 0;
      for (int i=0; i<n1; ++i) {   //a
        // digit i of a times digit j of b, considering carry value
        val = (num1Rev[i] - '0') * (num2Rev[j] - '0') + carry + (res[i+j] - '0');
        // the target digit of result is i+j
        res[i+j] =   '0' + val%10;
        carry = val/10;
      }
      if (carry > 0)  // the highest digit at current round
        res[j+n1] = '0' + carry;
    }

    // we need to get rid of the 0 at the end of res;
    int i = n1+n2-1;
    while (i>=0) {
      if (res[i] == '0')
        i--;
      else 
        break;
    }

    if (i < 0) return "0";

    res = res.substr(0, i+1); // get rid of zeors
    
    // reverse res;
    return reverseStr(res);

  }

  void test() {

   std::string num1 = "123";
   std::string num2 = "456";
   std::cout << "num1 = " << num1 << ", "  << "num2 = " << num2 <<", " <<"res = " << solve(num1,num2) << std::endl;


  }

};
