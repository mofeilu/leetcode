/*130. Surrounded Regions

Given a 2D board containing 'X' and 'O' (the letter O), 
capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that 
surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

Explanation:

Surrounded regions shouldn’t be on the border, 
which means that any 'O' on the border of the board are not flipped to 'X'.Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/

class SurroundedRegion130 
{

public:
  
  void DFS(int i, int j, vector<vector<char> > & board) {
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ) return; // out of border
    if (board[i][j] != 'O') return; // 'C' or 'X'
    board[i][j] = 'C'; // "confirmed" state
    DFS(i-1,j,board);
    DFS(i+1,j,board);
    DFS(i,j-1,board);
    DFS(i,j+1,board);
  }

  // the idea is to start from border 'O', and go with DFS, change all elem along the path
  // from 'O' to 'C'.  at the end. change 'C' to 'O' and 'O' to 'X'
  void solve(vector<vector<char>>& board) {
    int M = board.size();
    if (M == 0) return;
    int N = board[0].size();
    // go over the border, find 'O' and start DFS

    for (int i=0; i<M; ++i) {
      if(board[i][0] == 'O')
        DFS(i,0,board);
      if(board[i][N-1] == 'O')
        DFS(i,N-1,board);
    }

    for (int i=0; i<N; ++i) {
      if(board[0][i] == 'O')
        DFS(0,i,board);
      if(board[M-1][i] == 'O')
        DFS(M-1,i,board);  
    }

    // final summarize
    for (int i=0; i<M; ++i)
      for (int j=0; j<N; ++j)
        if (board[i][j] == 'O')
          board[i][j] = 'X';  
        else if (board[i][j] == 'C')
          board[i][j] = 'O';  


  }

  void test()
  {
    vector<vector<char>> board;
    board = {
              {'X', 'X', 'X', 'X'},
              {'X', 'O', 'O', 'X'},
              {'X', 'X', 'O', 'X'},
              {'X', 'O', 'X', 'X'}};
    cout << "input board :\n";
    print_data(board);
    cout << "output board: \n";
    solve(board);
    print_data(board);          



  }

};
