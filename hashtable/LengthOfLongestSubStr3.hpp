/*3. Longest Substring Without Repeating Characters
Given a string, find the length of the 
longest substring without repeating characters.

Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
   Note that the answer must be a substring, 
   "pwke" is a subsequence and not a substring.
*/


class LengthOfLongestSubStr3
{
public:

  //idea: use hash map to store the last pos of visited char
  //when traverse string, keep updating hash map length of non-repeating substr
  int solve(std::string s) {
    int N = s.size(); 
    if (N == 0) return 0;
    int maxLen = 1;
    int startPos = 0; // start position of non-repeating substr so far
    
    // last position of visited char so far
    std::unordered_map<char, int> pos;
    pos[s[0]] = 0;

    for (int i=1; i<N; ++i) {
      if (pos.find(s[i]) == pos.end()) {
        pos[s[i]] = i;
        //if (i == N-1) // last char, we need to summarize anyway
        //  maxLen = std::max(i-startPos+1, maxLen);
      } else { 
          if (pos[s[i]] < startPos) { // repeating char not in range
            pos[s[i]] = i;
          } else {  // repeating char in range
            maxLen = std::max(i-startPos, maxLen);
            startPos =  pos[s[i]] + 1;
            pos[s[i]] = i;
          }
      }
      if (i == N-1)  // corner case, at the last char, we always need to summarize
        maxLen = std::max(i-startPos+1, maxLen);

    }


    return maxLen;  

  }

  void test()
  {
    std::string s;
    s = "abcabcbb";
    std::cout << "string is " << s << ", length of Longest substr w/o repeating char is " << solve(s) << std::endl;
    s= "bbbbb";
    std::cout << "string is " << s << ", length of Longest substr w/o repeating char is " << solve(s) << std::endl;
    s = "pwwkew";
    std::cout << "string is " << s << ", length of Longest substr w/o repeating char is " << solve(s) << std::endl;
    s = "au";
    std::cout << "string is " << s << ", length of Longest substr w/o repeating char is " << solve(s) << std::endl;

  }
        




};
