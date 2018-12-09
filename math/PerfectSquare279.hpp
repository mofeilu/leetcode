/*
Given a positive integer n, 
// find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:
Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.

Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

class PerfectSquare279
{
public:
   /// the basic idea is recursion, but use dp
   /// will save redundent calculation
	int solve(int n) {
    int* dp = new int[n+1]; // 0 to n;
    dp[0] = 0;
    for (int i=1; i<=n; ++i) {
      dp[i] = INT_MAX;
      for (int j=1; j*j<=i; ++j) {
        dp[i] = std::min(dp[i], 1+dp[i-j*j]);
      } 
    }
     
    return dp[n];
  }


  void test() {

    int n = 12;
    std::cout << "n = " << n << " res = " << solve(n) << std::endl;
    n = 13;
    std::cout << "n = " << n << " res = " << solve(n) << std::endl;



  }



};


/* recursive method, do not really understand
public class Solution {
    public int numSquares(int n) {
        int res = n, num =2;
        while(num * num <=n){
            int x = n/(num*num), y = n%(num*num);
            res = Math.min(res, x + numSquares(y));
            ++num;
        }

        return res;
    }
}*/

/*  
Solution 3. DP. this is a forward dp question,
 using an array dp[], dp[i] means the number 
 need to square-sum up to i, then, for all the j from 1 to i+jj <=n; 
 calculate dp[i+jj] = ?, initially set each dp[i] equals to max.
public class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n+1];
        for(int i=1; i<=n; i++){
            dp[i] = Integer.MAX_VALUE;
        }
        dp[0]=0;
        for(int i=0; i<=n; i++){
            for(int j=1; i+ j*j <=n; j++){
                dp[i+j*j] = Math.min(dp[i+j*j], dp[i]+1);
            }
        }

        return dp[n];
    }
}*/
