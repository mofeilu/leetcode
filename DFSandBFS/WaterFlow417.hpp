/*417. Pacific Atlantic Water Flow

Given an m x n matrix of non-negative integers representing the height of 
each unit cell in a continent, the "Pacific ocean" touches the left and top 
edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell 
to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific 
and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] 
(positions with parentheses in above matrix).
*/


/*
idea: start from pacific coast, go DFS, mark all pos that 
flow to pacific.  then start from atlantic coast, go DFS,
make all pos that flow to atlantic, eventually we combine
*/
class WaterFlow417 {

public:
  // hPrev gives the hight of previous node
  void DFS(int i, int j, vector<vector<int> > & mat, vector<vector<bool> > & status, int hPrev)
  {
    if (i<0 || i >= mat.size() || j<0 || j >= mat[0].size()) return;
    if (status[i][j]) return; // visited
    // current node must be higher than previous node to continue
    if (mat[i][j] >= hPrev) {
      status[i][j] = true; 
      DFS(i-1, j, mat, status, mat[i][j]);
      DFS(i+1, j, mat, status, mat[i][j]);
      DFS(i,j-1,  mat, status, mat[i][j]);
      DFS(i,j+1,  mat, status, mat[i][j]);
    }
  }


  vector<pair<int, int>> solve(vector<vector<int>>& matrix) {
    int M = matrix.size();
    if (M == 0) return {};
    int N = matrix[0].size();
    vector<vector<bool> > pac(M, vector<bool>(N, false));
    vector<vector<bool> > alt(M, vector<bool>(N, false));

    for (int i=0; i<M; ++i) {
      DFS(i,0,matrix,pac, 0);
      DFS(i,N-1,matrix,alt, 0);
    }

    for (int i=0; i<N; ++i) {
      DFS(0,i,matrix,pac, 0);
      DFS(M-1,i,matrix,alt,0);
    }

    vector<pair<int,int> > res;
    for (int i=0; i<M; ++i)
      for (int j=0; j<N; ++j)
        if (pac[i][j] && alt[i][j])  
          res.push_back(make_pair(i,j));

    return res;    
  }


  void test()
  {
    vector<vector<int> > matrix;
    vector<pair<int, int>> res;

    matrix = {{1,   2,  2,  3,  5},
       {3,   2,  3,  4,  4},
       {2,   4,  5,  3,  1},
       {6,   7,  1,  4,  5},
       {5,   1,  1,  2,  4}};

    cout << "height matrix : \n";
    print_data(matrix);
    cout << "nodes that flow to both ocean : \n";
    print_data(solve(matrix));   

  }

};
