/*712. Minimum ASCII Delete Sum for Two Strings

Given two strings s1, s2, find the lowest ASCII 
sum of deleted characters to make two strings equal.

Example 1:
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII 
value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 
is the minimum sum possible to achieve this.

Example 2:
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d]+101[e]+101[e] to the sum.  
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", 
and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", 
we would get answers of 433 or 417, which are higher.

Note:
0 < s1.length, s2.length <= 1000.
All elements of each string will have an ASCII value in [97, 122]
which is a to z.*/

class minimumDeleteSum712
{
public:
	// idea: MDS(m, n) = MDS(m-1,n-1), if s1[m] == s2[n]
	// otherwise: MDS(m, n) = min( MDS(m-1,n) + s1[m], MDS(m, n-1) + s2[n])
	int solve(std::string s1, std::string s2) {
		int M = s1.size(); int N = s2.size();
		
    // we take into account the case of empty str
    // s1 pos (-1 to M-1) , -1 means empty str
    // s2 pos (-1 to N-1)
		std::vector<std::vector<int> > MDS(M+1, std::vector<int>(N+1, 0));
		// we span the first row
    MDS[0][0] = 0;
    for (int n=0; n<N; ++n)
      MDS[0][n+1] = MDS[0][n] + (int)s2[n];

    // we span row by row
    for (int m=0; m<M; ++m) {
      MDS[m+1][0] = MDS[m][0] + (int)s1[m];

      for (int n=0; n<N; ++n) {
        if (s1[m] == s2[n])
          MDS[m+1][n+1] = MDS[m][n];
        else 
          MDS[m+1][n+1] = std::min(MDS[m][n+1]+(int)s1[m], MDS[m+1][n]+(int)s2[n]);
      }
    }

    return MDS[M][N];
	}


	void test()
	{
		std::string s1, s2;
		s1 = "delete";
		s2 = "leet";

		std::cout << "s1 = " << s1 << ", " << "s2 = " << s2 << std::endl;
		std::cout << "MDS = " << solve(s1,s2) << std::endl;

	}

};
