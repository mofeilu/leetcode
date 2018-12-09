/*200. Number of Islands
Given a 2d grid map of '1's (land) and '0's (water), 
count the number of islands. An island is surrounded by 
water and is formed by connecting adjacent lands horizontally 
or vertically. You may assume all four edges of the grid 
are all surrounded by water.

Example 1:
Input:
11110
11010
11000
00000
Output: 1

Example 2:
Input:
11000
11000
00100
00011
Output: 3
*/

using namespace std;

class NumOfIslands200 {
public:
   void DFS(int i, int j, vector<vector<char> > & grid,
          vector<vector<bool> > & visited)
   {
     if (i >= grid.size() || j >= grid[0].size()) return;
     if (visited[i][j] || grid[i][j] == '0') return;
     visited[i][j] = true;

     DFS(i+1, j, grid, visited);
     DFS(i-1, j, grid, visited);
     DFS(i, j-1, grid, visited);
     DFS(i, j+1, grid, visited);
   }

  // this is a typical DFS problem, we just need
  // to remember visited sites
  int solve(vector<vector<char>>& grid) {
    int M = grid.size();
    if (M == 0) return 0;
    int N = grid[0].size();

    vector<vector<bool> > visited(M, vector<bool>(N, false));
    int res = 0;
    for (int i=0; i<M; ++i) 
      for (int j=0; j<N; ++j)
        if (!visited[i][j] && grid[i][j] == '1') {
            ++res;
            DFS(i,j,grid,visited);
        }

    return res;  
  }

  //////////// a refinement that is faster ////////////////
  void DFS1(int i, int j, vector<vector<char> > & grid)
   {
     if (i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return;
     grid[i][j] = '0';
     DFS1(i+1, j, grid);
     DFS1(i-1, j, grid);
     DFS1(i, j-1, grid);
     DFS1(i, j+1, grid);
   }

  // this is a typical DFS problem, trick here is that we 
  // modify grid[i][j] to '0' if visited, do not need
  // extra visited array 
  int solve1(vector<vector<char>>& grid) {
    int M = grid.size();
    if (M == 0) return 0;
    int N = grid[0].size();

    int res = 0;
    for (int i=0; i<M; ++i) 
      for (int j=0; j<N; ++j)
        if (grid[i][j] == '1') {
            ++res;
            DFS1(i,j,grid);
        }

    return res;  
  }

  void test() {
    vector<vector<char> > grid;
    grid = 
    {{'1','1','0','0','0'},
     {'1','1','0','0','0'},
     {'0','0','1','0','0'},
     {'0','0','0','1','1'}};
    std::cout<<"input grid: \n";
    print_data(grid);
    std::cout << "# of islands : " << solve1(grid) << endl;

  }

};
