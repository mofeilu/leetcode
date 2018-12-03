/*Given a non-empty string s and a dictionary wordDict 
containing a list of non-empty words, 
determine if s can be segmented into a space-separated 
sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

Example 1:
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" 
can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/
#include <string>
class wordBreak139
{
public:
  bool matchWords(std::string & s, int istart, std::vector<std::string>& wordDict)
  {
    if (istart >= s.size()) return true;
    for (int i=0; i<wordDict.size(); ++i)
      if (s.compare(istart, wordDict[i].size(), wordDict[i]) == 0) 
        if (matchWords(s, istart+wordDict[i].size(), wordDict))
          return true;
    return false;    
  }

  // this is just too slow
  bool solve(std::string s, std::vector<std::string>& wordDict) {
    return matchWords(s, 0, wordDict);

  }

  void test()
  {
    std::string s;
    std::vector<std::string> wordDict;

    s = "applepenapple";  wordDict = {"apple", "pen"};
    std::cout << "s = " << s <<", " <<"wordDict = ";
    print_data(wordDict);
    std::cout << "output = " << (solve(s, wordDict) ? "true" : "false") << std::endl;

    s = "catsandog";  wordDict = {"cats", "dog", "sand", "and", "cat"};
    std::cout << "s = " << s <<", " <<"wordDict = ";
    print_data(wordDict);
    std::cout << "output = " << (solve(s, wordDict) ? "true" : "false") << std::endl;


  }
  




};
