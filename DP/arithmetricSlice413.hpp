/*A sequence of number is called arithmetic if 
it consists of at least three elements and if the difference 
between any two consecutive elements is the same.

For example, these are arithmetic sequence:
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. 
A slice of that array is any pair of integers (P, Q) 
such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. 
In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.


Example:
A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in 
A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
*/

class arithmetricSlice413
{
public:
  // find the number of arithemetic slices that end at i
  void findNum(std::vector<int> const & A, int i, std::vector<int> & nums)
  {
    if (i < 2) {
      nums[i] = 0;
      return;
    }
    
    findNum(A, i-1, nums);
    int step = A[i-1] - A[i-2];
    if (A[i] - A[i-1] == step)
      nums[i] = nums[i-1] + 1; // the extra 1 is coming from prev 2 elems
  }
  
  int solve(std::vector<int>& A) {
    if (A.size() < 3) return 0;
    std::vector<int> nums(A.size(), 0);
    findNum(A, (int)A.size()-1, nums);
    int res = 0;
    for (int i=0; i<nums.size(); ++i)
      res += nums[i];
    return res;
  }

  void test() {
    std::vector<int> A = {1, 2, 3, 4};
    std::cout<<"input vec : ";
    print_data(A);
    std::cout<<"# of slices : " << solve(A) << std::endl;
    A = {};
    std::cout<<"input vec : ";
    print_data(A);
    std::cout<<"# of slices : " << solve(A) << std::endl;

  }
};
