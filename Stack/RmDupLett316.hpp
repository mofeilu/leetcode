/*316. Remove Duplicate Letters
Given a string which contains only lowercase letters, 
remove duplicate letters so that every letter appear once and only once. 
You must make sure your result is the smallest in lexicographical 
order among all possible results.

Example 1:
Input: "bcabc"
Output: "abc"

Example 2:
Input: "cbacdcbc"
Output: "acdb"
*/   


class RmDupLett316 {

public:
  string solve(string s) {
     string res;
     for (char c : s) {
       int pos = res.find(c);
       if (pos == string::npos) 
          res.push_back(c);
       else {
          string strNew = res;
          strNew.erase(pos,1);
          strNew.push_back(c);
          if (strNew < res)
            res = strNew;
       } 
           
     }
    return res;
  }

  void test()
  {
    string s;
    s = "cbacdcbc";
    cout << "input str : " << s << endl;
    cout << "simplified str : " << solve(s) << endl;
    s = "bcabc";
    cout << "input str : " << s << endl;
    cout << "simplified str : " << solve(s) << endl;
  }

};
