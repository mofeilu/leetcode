/*542. 01 Matrix
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1: 
Input:
0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0

Example 2: 
Input:
0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
*/

// idea: the DP solution is natural, min dist could from any 4 dir,
// so we have one DP sweep from top down (top, left dir), and one DP swwep from
// bottom up (bot, right dir), we select the min of the two.
class ZeroOneMatrix542 {

public:
  
  vector<vector<int>> solve(vector<vector<int>>& matrix) {
    int M = matrix.size();
    int N = matrix[0].size();
    int maxDist = 10000; // # of elem < 10000
    vector<vector<int> > dp(M, vector<int>(N,maxDist)); // top down
        
    // top down dp
    for (int i=0; i<M; ++i)
      for (int j=0; j<N; ++j) {
        if (matrix[i][j] == 0) {
          dp[i][j] = 0;
        } else {
          if (i > 0)
            dp[i][j] = min(dp[i][j],dp[i-1][j] + 1);
          if (j > 0)
            dp[i][j] = min(dp[i][j],dp[i][j-1] + 1);
        }
      }
    
    // bot up dp
    for (int i=M-1; i>=0; --i)
      for (int j=N-1; j>=0; --j) {
        if (i < M-1)
          dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
        if (j < N-1)
          dp[i][j] = min(dp[i][j], dp[i][j+1]+1);
      }

    return dp;  
  }

  void test()
  {
    vector<vector<int> > matrix, dist;
    matrix = {
    {0, 0, 0},
    {0, 1, 0},
    {1, 1, 1}};

    std::cout << "input matrix : \n";
    print_data(matrix);
    std::cout << "output dist : \n";
    print_data(solve(matrix));
  }

};
