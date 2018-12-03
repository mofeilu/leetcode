/*718. Maximum Length of Repeated Subarray
Given two integer arrays A and B, 
return the maximum length of an subarray 
that appears in both arrays.

Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].
Note:
1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
*/


class findLength718
{
public:
   /// note: below ( solve() )is to find longest common subsequency
   /// but this problem is to find longest common subarray (continum subsequence)
  /* idea of finding longest common subsequence: 
   define the length of longest common subsequency
   of A up to pos m and B up to pos n as:  LCS(m,n),
   we have the following resursion:
   if A[m] == B[n] : LCS(m,n) = LCS(m-1, n-1) + 1
   else : LCS(m,n) = max(LCS(m-1,n), LCS(m, n-1)
   */
  
  int solve(std::vector<int>& A, std::vector<int>& B) {
    int M = A.size(); int N = B.size();
    if (M == 0 || N == 0) return 0;

    //  M*N matrix
    std::vector<std::vector<int> > LCS(M, std::vector<int>(N, 0));
    
    // we span the first row
    LCS[0][0] = (A[0] == B[0]) ? 1 : 0;
    for (int n=1; n<N; ++n)
      LCS[0][n] = (A[0] == B[n]) ? 1 : LCS[0][n-1];

    // we span row by row
    for (int m=1; m<M; ++m) {
      LCS[m][0] = (A[m] == B[0]) ? 1 : LCS[m-1][0];

      for (int n=1; n<N; ++n) {
        if (A[m] == B[n])
          LCS[m][n] = LCS[m-1][n-1] + 1;
        else 
          LCS[m][n] = std::max(LCS[m-1][n], LCS[m][n-1]);
      }
    }

    return LCS[M-1][N-1];


  }

  /// this the right solution to find the length of longest common subarray
  /* idea:define the length of longest common subarray
   that end exactly at m in A and n in B as LCS(m,n)
   if A[m] == B[n] : LCS(m,n) = LCS(m-1,n-1) + 1;
   else : LCS(m,n) = 0
  */
  int solve1(std::vector<int>& A, std::vector<int>& B)
  {
    int M = A.size(); int N = B.size();
    int lcs_max = 0;
    int lcs_pre;
    
    // we span each diagnal of upper triangle
    for (int i=0; i<N; ++i) { 
      lcs_pre = 0;
      int m = 0; int n = i;
      while (m<N && n <N) {
        lcs_pre = (A[m] == B[n]) ? lcs_pre + 1 : 0;
        lcs_max = std::max(lcs_max, lcs_pre);
        m++; n++;
      }
    }

    // we span each diagnal of lower triangle
    for (int i=1;i<M; ++i) {
      lcs_pre = 0;
      int m = i; int n = 0;
      while (m<N && n <N) {
        lcs_pre = (A[m] == B[n]) ? lcs_pre + 1 : 0;
        lcs_max = std::max(lcs_max, lcs_pre);
        m++; n++;
      }
    }

    return lcs_max;
  }


  void test()
  {
    std::vector<int> A = {1,2,3,2,1};
    std::vector<int> B = {3,2,1,4,7};

    std::cout << "input vec A, B : \n";
    print_data(A);
    print_data(B);
    std::cout<< "LCS = " << solve1(A,B) << std::endl;

    A = {0,1,1,1,1};
    B = {1,0,1,0,1};
    std::cout << "input vec A, B : \n";
    print_data(A);
    print_data(B);
    std::cout<< "LCS = " << solve1(A,B) << std::endl;


  }

};
