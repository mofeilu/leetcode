/*
Roman numerals are represented by seven different 
symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000                                                                                                   
For example, two is written as II in Roman numeral, 
just two one's added together. 
Twelve is written as, XII, which is simply X + II. 
The number twenty seven is written as XXVII, 
which is XX + V + II.

Roman numerals are usually written largest to smallest 
from left to right. However, the numeral for four is not IIII. 
Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. 
The same principle applies to the number nine,which is written 
as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. 
Input is guaranteed to be within the range from 1 to 3999.
*/

class IntToRoman12 
{

public:

  std::string solve(int num) {
  	std::string rStr = ""; // start with empty string
  	int res = num;

  	int currVal = res/1000;
  	if (currVal > 0)
  		for (int i=0; i<currVal; ++i)
  		   rStr += "M";
    res = res - currVal*1000;
    
    currVal = res/100;
    if (currVal == 9) {
      rStr += "CM";
    } else if (currVal == 4) {
      rStr += "CD";
    } else if (currVal >= 5) {
      rStr += "D";
      for (int i=0; i<currVal-5; ++i)
        rStr += "C";
    } else {
      for (int i=0; i<currVal; ++i)
        rStr += "C";
    }
    res = res - currVal*100;


    currVal = res/10;
    if (currVal == 9) {
      rStr += "XC";
    } else if (currVal == 4) {
      rStr += "XL";
    } else if (currVal >= 5) {
      rStr += "L";
      for (int i=0; i<currVal-5; ++i)
        rStr += "X";
    } else {
      for (int i=0; i<currVal; ++i)
        rStr += "X";
    }
    res = res - currVal*10;

    currVal = res;
     if (currVal == 9) {
      rStr += "IX";
    } else if (currVal == 4) {
      rStr += "IV";
    } else if (currVal >= 5) {
      rStr += "V";
      for (int i=0; i<currVal-5; ++i)
        rStr += "I";
    } else {
      for (int i=0; i<currVal; ++i)
        rStr += "I";
    }

    return rStr;

  }


  void test() {
    int n = 27;
    std::cout << "n = " <<  n << " roman num = " << solve(n) << std::endl;
    n = 12;
    std::cout << "n = " <<  n << " roman num = " << solve(n) << std::endl;

  }




};
