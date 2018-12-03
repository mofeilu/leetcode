/*Given a string s, find the longest palindromic 
subsequence's length in s. 
You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
*/

//idea: dp[i][j] the length of the longest substr with start and end
// index i, j. 
// state transision:  dp[i][j] = dp[i+1][j-1] + 2 if s[i] == s[j]
// otherwise dp[i][j] = max(dp[i+1][j], dp[i][j-1])
class longestPalindromeSub516 {
public:
  int solve(std::string s) {
    int N = s.size();
    if (N == 0) return 0;
    std::vector<std::vector<int> > dp(N, std::vector<int>(N, 0));
    for (int i=N-1; i>=0; --i) {
      dp[i][i] = 1;
      for (int j=i+1; j<N; ++j) {
        if (s[i] == s[j])
          dp[i][j] = dp[i+1][j-1] + 2; // no warry about bound violation here
        else
          dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
      }    
    }

    return dp[0][N-1];
        
  }

  void test() {
    std::string s;
    s = "bbbab"; 
    std::cout << "input str = " << s << " longest palindrome sub Sequence : " << solve(s) << std::endl;
    s = "cbbd";
    std::cout << "input str = " << s << " longest palindrome sub Sequence : " << solve(s) << std::endl;

  }

    

};
