/*Given a string s, find the longest 
palindromic substring in s. 
You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"*/
#include <string> 
#include <map>
#include <vector>
#include <iostream>

class LongestPalindrome5
{
public:

  void findSubStr(std::string const & s,  int endPos, 
      std::map<int, std::vector<int> > & subStrMap) 
  {
    if (endPos < 0) return;

    findSubStr(s, endPos-1, subStrMap);

    // first consider single char string
    subStrMap[endPos] = {endPos};

    // then two char string
    if (endPos > 0) 
      if (s[endPos] == s[endPos-1])
        subStrMap[endPos].push_back(endPos-1);

    // then consider combinaiton with already found sub str
    if (subStrMap.find(endPos-1) != subStrMap.end()) 
      for (int k=0; k<subStrMap[endPos-1].size(); ++k) {
        int i = subStrMap[endPos-1][k];
        if (i > 0)
          if (s[i-1] == s[endPos])
            subStrMap[endPos].push_back(i-1);

      }

  }

  /// this seems slow
  std::string solve( std::string s) {
    // subStrMap[j][k] = i, gives the starting pos i of  
    // one Palindrome substr that end in pos j
    std::map<int, std::vector<int> > subStrMap;

    findSubStr(s, (int)s.size()-1, subStrMap);

    std::string res;
    int maxLen = 0; 
    for (auto it : subStrMap)
      for (int i=0; i< it.second.size(); ++i) 
        if (it.first - it.second[i] + 1 > maxLen) {
          maxLen = it.first - it.second[i] + 1;
          res = s.substr(it.second[i], it.first-it.second[i]+1);
        }
      
    return res;  
  }


  void test() {
    std::string strIn = "babad";
    std::cout << "input str : " << strIn << ", LongestPalindrome5 : " << solve(strIn) << std::endl;
    strIn = "cbbd";
    std::cout << "input str : " << strIn << ", LongestPalindrome5 : " << solve(strIn) << std::endl;
    strIn = "a";
    std::cout << "input str : " << strIn << ", LongestPalindrome5 : " << solve(strIn) << std::endl;

  }





};
