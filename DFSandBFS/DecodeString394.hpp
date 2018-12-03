/*394. Decode String
Given an encoded string, return it's decoded string.

The encoding rule is: 
k[encoded_string], where the encoded_string inside the square 
brackets is being repeated exactly k times. Note that k is 
guaranteed to be a positive integer.

You may assume that the input string is always valid; 
No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not 
contain any digits and that digits are only for those repeat 
numbers, k. For example, there won't be input like 3a or 2[4].

Examples:
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/
#include <ctype.h>
using namespace std;

class DecodeString394 {

public:
  /* the idea is to use two stack A, B. A for number , B for the other 
  chars, in B, whenever we encouter a ']', we find the all the chars 
  backward up to a '[', and replace it with a multiple from the pop of A.
  */
  
  // find backword the first '[', replace all the char up to that
  // with its multiple given by mul
  void decode(string & res, int mul) {
    int pos = (int)res.size()-1;
    while (res[pos] != '[') pos--;
    string str = res.substr(pos+1); 
   
    res.resize(pos); // delete all char up to '['
    for (int i=0; i<mul; ++i)
      res.insert(res.end(),str.begin(), str.end());
  }

  string solve(string s) {
    vector<int> num; // used as a stack for number
    string res; // used as a stack for char
    int i=0;
    while (i<s.size()) {
      if(isdigit(s[i])) {
        int mul = 0;
        while (isdigit(s[i])) { // find number more than 1 digit
          mul = 10*mul + s[i]-'0';
          ++i;
        }
        num.push_back(mul);
      } else if (s[i] != ']') {
        res.push_back(s[i]);
        ++i;
      } else {  // need to pop
        int mul = num.back();
        num.pop_back();
        decode(res, mul);
        ++i;
      }
     
    }

    return res;
  }

  void test()
  {
    string s;
    s = "2[abc]3[cd]ef";
    cout << "encoding str is " << s << endl;
    cout << "decoded str is " << solve(s) << endl;

    s= "3[a2[c]]";
    cout << "encoding str is " << s << endl;
    cout << "decoded str is " << solve(s) << endl; 

    s = "10[leetcode]";
    cout << "encoding str is " << s << endl;
    cout << "decoded str is " << solve(s) << endl; 
  }

};
