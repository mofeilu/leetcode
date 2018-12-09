/*6. ZigZag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern 
on a given number of rows like this: 
(you may want to display this pattern in a fixed font 
for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make 
this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
*/

class ZigZagConversion6 {

public:
  // idea: we can predict the position of letter in each row
  string solve(string s, int numRows) {
    string res;
    int N = s.size();
    if (numRows == 1) return s;
    // distance beween letters in the first row
    int dist0 = 2 * (numRows - 1);  int dist1 = 0;
     // first row
    int i = 0;
    while (i < N) { res += s[i];  i += dist0; }

    // from 2nd row to 2nd last row
    for (int r = 1; r < numRows-1; ++r) {
      dist0 -= 2;  dist1 += 2;
      bool useDist0 = true;
      int i = r;
      while (i < N ) { 
        res += s[i];  
        i += (useDist0 ? dist0 : dist1);
        useDist0 = !useDist0;  // alternate
      }
    }

    // last row
    i =  numRows - 1;  dist0 = 2 * (numRows - 1);
    while (i < N) { res += s[i]; i += dist0;}


    return res;

  }

  void test()
  {
    string s; int numRows;
    s = "PAYPALISHIRING"; numRows = 3;
    cout << "input str : " << s << endl;
    cout << "number of rows : " << numRows << endl;
    cout << "output str : " << solve(s, numRows) << endl;


    s = "PAYPALISHIRING"; numRows = 4;
    cout << "input str : " << s << endl;
    cout << "number of rows : " << numRows << endl;
    cout << "output str : " << solve(s, numRows) << endl;

  }

};
