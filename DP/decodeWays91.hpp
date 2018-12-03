/*A message containing letters from A-Z is 
being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, 
determine the total number of ways to decode it.

Example 1:
Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:
Input: "226"
Output: 3
Explanation: 
It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/


class decodeWays91
{
public:
  
  void deCodeWaysHelper(std::string const & s,  int i, int & case1, int & case2, int & case3)
  {
    if(i==0) {
      if (s[i] == '1') {
        case1 = 1; case2 = case3 = 0;
      } else if (s[i] == '2') {
        case2 = 1; case1 = case3 = 0;
      }else if (s[i] == '0') {
        case1 = case2 = case3 = 0;
      }else {
        case1 = case2 = 0; case3 = 1;
      }
      return;
    }

    int case1Prev, case2Prev, case3Prev;

    deCodeWaysHelper(s, i-1, case1Prev, case2Prev, case3Prev);
    case1 = case2 = case3 = 0;
    case1 =  (s[i] == '1') ? case1Prev + case2Prev + case3Prev : 0;
    case2 =  (s[i] == '2') ? case1Prev + case2Prev + case3Prev : 0;
    case3 =   case1Prev;  // '1' is always ok to combine
    if (s[i] - '1' <= 5)  // '2' can only combine with 0 to 6
      case3 +=  case2Prev;
    if (s[i] - '1' > 1) { // 3 and above, without combine
      case3 += case1Prev + case2Prev + case3Prev;
    }

  }

  int solve(std::string s) {
   /* idea, with can consider the decode ways up to pos i of s
      then up to pos i+1, the decode way is formed by either add s[i+1],
      or combine s[i+1] with previous code.
      three case for previous code:
      "1": can either combine or add
      "2": for currend char 1 to 6, can combine or add, otherwise can only add
      "all other": can only add
   */ 
   int case1, case2, case3; 
   deCodeWaysHelper(s, (int)s.size()-1, case1, case2, case3);
   return case1 + case2 + case3;
  }

  void test()
  {
    std::string s;
    s = "12";
    std::cout << "input str = " << s <<", " << "decode ways = " << solve(s) << std::endl;
    s = "226";
    std::cout << "input str = " << s <<", " << "decode ways = " << solve(s) << std::endl;
    s = "0";
    std::cout << "input str = " << s <<", " << "decode ways = " << solve(s) << std::endl;
    s = "100";
    std::cout << "input str = " << s <<", " << "decode ways = " << solve(s) << std::endl;

  }




};
