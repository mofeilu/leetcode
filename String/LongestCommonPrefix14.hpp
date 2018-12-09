/*14. Longest Common Prefix
Write a function to find the longest common 
prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/

class LongestCommonPrefix14 {

public:
  // idea: se simply iterate from begin and compare each char 
  string solve(vector<string>& strs) {
    if (strs.empty()) return "";
    int i = 0; char c;
    while (true) {
      if (i >= strs[0].size()) break;
      c = strs[0][i];
      bool isSame = true;
      for (int k=1; k<strs.size(); ++k) 
        if (i >= strs[k].size() || strs[k][i] != c) {
          isSame = false; break;
        }
      if (!isSame) break;  
      ++i;
    }

    if (i<0) return "";

    return strs[0].substr(0, i);
  }

  void test()
  {
    vector<string> strs ;

    strs = {"flower","flow","flight"};
    cout << "input strs : ";
    print_data(strs);
    cout << "longest common prefix : " << solve(strs) << endl;

    strs =  {"dog","racecar","car"};
    cout << "input strs : ";
    print_data(strs);
    cout << "longest common prefix : " << solve(strs) << endl;
  }



};
