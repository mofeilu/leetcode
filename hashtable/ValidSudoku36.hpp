/*36. Valid Sudoku
Determine if a 9x9 Sudoku board is valid. 
Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, 
where empty cells are filled with the character '.'.

Example 1:
Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true

Example 2:
Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.
*/


class ValidSudoku36
{
public:
  bool updateBuffer(std::vector<std::vector<char>>& board, 
                    std::set<int>& buffer, int m, int n)
  {
    if (board[m][n] == '.') return true;
    if (buffer.find(board[m][n]) != buffer.end()) // repeat
      return false;
    else
      buffer.insert(board[m][n]);
    return true;
   }

  bool solve(std::vector<std::vector<char>>& board) {
     std::set<int> buffer;
     // check all the rows
     for (int m=0; m<9; ++m) {
       buffer.clear();
       for (int n = 0; n<9; ++n) 
         if(!updateBuffer(board, buffer,m,n)) return false;
       //if (buffer.empty()) return false;
     }

     // check all the cols
     for (int n=0; n<9; ++n) {
       buffer.clear();
       for (int m = 0; m<9; ++m)
         if(!updateBuffer(board, buffer,m,n)) return false;
       
       //if (buffer.empty()) return false;
     }

     // check all 3x3 blocks
     for (int i = 0; i<3; ++i)
      for (int j=0; j<3; ++j) {
         buffer.clear();
         for (int m=3*i; m<3*i+3; ++m)
           for (int n=3*j; n<3*j+3; ++n) 
             if(!updateBuffer(board, buffer,m,n)) return false;
         //if (buffer.empty()) return false;
      }



     return true;

  }

  void test()
  {
    std::vector<std::vector<char> > board;
    board = 
     { {'8','3','.','.','7','.','.','.','.'},
      {'6','.','.','1','9','5','.','.','.'},
      {'.','9','8','.','.','.','.','6','.'},
      {'8','.','.','.','6','.','.','.','3'},
      {'4','.','.','8','.','3','.','.','1'},
      {'7','.','.','.','2','.','.','.','6'},
      {'.','6','.','.','.','.','2','8','.'},
      {'.','.','.','4','1','9','.','.','5'},
      {'.','.','.','.','8','.','.','7','9'} };

    std::cout << " the sudoku board : \n";
    print_data(board);
    std::cout<< " this is " << (solve(board) == true ? "valid" : "not valid") << std::endl;  


    board = 
    {{'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}};

     std::cout << " the sudoku board : \n";
    print_data(board);
    std::cout<< " this is " << (solve(board) == true ? "valid" : "not valid") << std::endl;  


  }



};



