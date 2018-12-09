/*547. Friend Circles

There are N students in a class. Some of them are friends, 
while some are not. Their friendship is transitive in nature. 
For example, if A is a direct friend of B, and B is a direct 
friend of C, then A is an indirect friend of C. 
And we defined a friend circle is a group of students 
who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship 
between students in the class. If M[i][j] = 1, then the ith and jth 
students are direct friends with each other, otherwise not. 
And you have to output the total number of friend circles 
among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, 
so they are in a friend circle. The 2nd student himself 
is in a friend circle. So return 2.

Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, 
the 1st and 2nd students are direct friends,so the 0th and 2nd 
students are indirect friends. All of them are in the same 
friend circle, so return 1.

Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.
*/
using namespace std;
/// note: this is not the same as Number of islands(problem 200)
/// here we deal with graph connectivity not matrix nbrs
/// the trick here is we directly modify M to track visited or not
class FriendCircles547 {
public:
   void DFS(int i, vector<vector<int> > & M)
   {
     if (M[i][i] == 0) return;
     M[i][i] = 0; // tag visited 
     for (int j=0; j<M.size(); ++j)
      // j connect to i and not visited yet
      if (M[i][j] == 1 && M[j][j] == 1) 
        DFS(j, M);
   }

  int solve(vector<vector<int>>& M) {
    int N = M.size();
    if (N == 0) return 0;
    
    int res = 0;
    for (int i=0; i<N; ++i) 
      if (M[i][i] == 1) {
        res++;
        DFS(i, M);
      }
    return res;  
      
  }

  void test()
  {
    vector<vector<int> > M;
    M = 
    {{1,1,0},
     {1,1,0},
     {0,0,1}};
    std::cout<<"input M: \n";
    print_data(M);
    std::cout << "# of circles : " << solve(M) << endl;
 
    M = 
    {{1,1,0},
     {1,1,1},
     {0,1,1}};
     std::cout<<"input M: \n";
    print_data(M);
    std::cout << "# of circles : " << solve(M) << endl;
    
    M = 
    {{1,0,0,1},
     {0,1,1,0},
     {0,1,1,1},
     {1,0,1,1}};
      std::cout<<"input M: \n";
    print_data(M);
    std::cout << "# of circles : " << solve(M) << endl; 

  }

};
