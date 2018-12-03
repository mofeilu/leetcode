/*Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, 
where n is the total number of rows in the triangle.
*/

/// idea: we recursively calculate from bottom to top
class triangle120
{
 public:
	int solve(std::vector<std::vector<int>>& triangle) {
    int r = (int)triangle.size() - 2;  // from the second last row
    while (r >= 0) {
      for (int i=0; i<(int)triangle[r].size(); ++i)
        triangle[r][i] += std::min(triangle[r+1][i], triangle[r+1][i+1]); 
      r--;
    }

    return triangle[0][0];
 	}


  void test()
  {
    std::vector<std::vector<int> > triInputs = {
           {2},
          {3,4},
         {6,5,7},
        {4,1,8,3}
    };

    std::cout << "inut triangle is : ";
    print_data(triInputs);
    std::cout <<"min path sum = " << solve(triInputs) << std::endl;

  }


};
