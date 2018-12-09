/*765. Couples Holding Hands
N couples sit in 2N seats arranged in a row and want to hold hands. 
We want to know the minimum number of swaps so that every couple is 
sitting side by side. A swap consists of choosing any two people, 
then they stand up and switch seats.

The people and seats are represented by an integer from 0 to 2N-1, 
the couples are numbered in order, the first couple being (0, 1), 
the second couple being (2, 3), and so on with the last couple being (2N-2, 2N-1).

The couples' initial seating is given by row[i] being the value 
of the person who is initially sitting in the i-th seat.

Example 1:
Input: row = [0, 2, 1, 3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.

Example 2:
Input: row = [3, 2, 0, 1]
Output: 0
Explanation: All couples are already seated side by side.
Note:

len(row) is even and in the range of [4, 60].
row is guaranteed to be a permutation of 0...len(row)-1.
*/

using namespace std;

class CouplesHoldingHands765 {

public:
  void swap(int i, int j, vector<int> & row, unordered_map<int, int> & pos) {
    int ri = row[i];
    int rj = row[j];
    row[i] = rj;
    row[j] = ri;
    pos[rj] = i;
    pos[ri] = j;
  }
  // idea: we can prove that the following strategy works:
  // read 2 space each time from the row, if the numbers in the 2 space are not couple
  // switch one of them with the corresponding couple number.
  // do this repeatedly untial the end of the row
  int solve(vector<int>& row) {
    int N = row.size();
    unordered_map<int, int> pos;  // position of each person
    for (int i=0; i<N; ++i)
      pos[row[i]] = i;

    int nSwap = 0;

    for (int i=0; i<(N/2); ++i) {
        if (row[2*i]%2 == 0 && row[2*i+1] != row[2*i]+1) {
          swap(2*i+1, pos[row[2*i]+1], row, pos);
           ++nSwap;
        } else if (row[2*i]%2 == 1 & row[2*i+1] != row[2*i]-1) {
          swap(2*i+1, pos[row[2*i]-1], row, pos);
           ++nSwap;
        }
    }
      
    return nSwap;

  }

  void test()
  {
    vector<int> row;
    row = {0, 2, 1, 3};
    cout << "input row vec : ";
    print_data(row);
    cout <<"min # of swap needed : " << solve(row) << std::endl;

    row = {3, 2, 0, 1};
    cout << "input row vec : ";
    print_data(row);
    cout <<"min # of swap needed : " << solve(row) << std::endl;

    row = {5,6,4,0,2,1,9,3,8,7,11,10};
    cout << "input row vec : ";
    print_data(row);
    cout <<"min # of swap needed : " << solve(row) << std::endl;



  }

};
