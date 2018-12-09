/*17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, 
return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) 
is given below. Note that 1 does not map to any letters.
2->abc
3->def
4->ghi
5->jkl
6->mno
7->pqrs
8->tuv
9->wxyz


Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer 
could be in any order you want.
*/

class LetterCombPhoneNum17 {

public:
  string numToLetters(int n) {
    switch(n) {
      case 2: return "abc"; break;
      case 3: return "def"; break;
      case 4: return "ghi"; break;
      case 5: return "jkl"; break;
      case 6: return "mno"; break;
      case 7: return "pqrs"; break;
      case 8: return "tuv"; break;
      case 9: return "wxyz"; break;
    }
  }



  vector<string> solve(string digits) {
    if (digits.size() == 0) return {};
    string init = numToLetters(digits[0]-'0');
    vector<string> res;
    for (int i=0; i<init.size(); ++i) {
      string tmp(1, init[i]);
      res.push_back(tmp);
    }

    for (int i=1; i<digits.size(); ++i) {
      string str = numToLetters(digits[i]-'0');
      vector<string> resNew;
      for (int m=0; m<res.size(); ++m) 
        for (int n=0; n<str.size(); ++n) {
          string tmp = res[m];
          tmp.push_back(str[n]);
          resNew.push_back(tmp);
        }
      res = resNew;  
    }
    return res;
  }

  void test()
  {
    string dig;
    dig = "23";
    cout << "input digits : " << dig << endl;
    cout << "output combinations : \n";
    print_data(solve(dig));

  }

};
