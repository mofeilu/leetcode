/*451. Sort Characters By Frequency
Given a string, sort it in decreasing order based on the 
frequency of characters.

Example 1:
Input:
"tree"
Output:
"eert"
Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
Input:
"cccaaa"
Output:
"cccaaa"
Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:
Input:
"Aabb"
Output:
"bbAa"
Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/


class SortCharByFreq451 {

public:

  string solve(string s) {
    unordered_map<char, int> count;
    for (char c : s) ++count[c];
    map<int, vector<char> > occ; // ordered map
    for (auto & it : count)
      occ[it.second].push_back(it.first);
    string res;
    for (auto & it : occ)
      for (char c : it.second)
          res = string(it.first, c) + res; // string(n, char) is valid
    return res;

  }

  void test()
  {
    vector<string> strs = {"tree","cccaaa", "Aabb"};
    for (string s : strs) {
      cout << "input str : " << s << endl;
      cout << "sorted str : " << solve(s) << endl;
    }

  }

};
