/*
A robot is located at the top-left corner of a m x n grid 
(marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid 
(marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

Example 2:
Input: m = 7, n = 3
Output: 28
*/

class uniquePath62
{
public:

  /// idea: any state only depend on the state of its right and below
  /// so we start from the bottom right corner, span bottom up, then
  /// right to left.

  int solve(int m, int n) {
    std::vector<int> preCol(n,0);
    std::vector<int> currCol(n,0);
    // span current col
    int colNum = m-1;
    while (colNum >= 0) {
      currCol[n-1] = preCol[n-1];
      if (colNum == m-1) currCol[n-1] = 1; // this is bottom right corner
      for (int r=n-2; r>=0; --r)
        currCol[r] = currCol[r+1] + preCol[r];
      colNum--; 
      preCol = currCol;
      //print_data(currCol);
    }

    return currCol[0]; // top left corner
       
  }

  void test() {
    int m, n;
    m = 3, n = 2;
    std::cout << " m, n = " << m <<", " << n <<", path # = " << solve(m,n) << std::endl;
  }



};
