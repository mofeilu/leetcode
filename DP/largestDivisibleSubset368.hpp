/*368. Largest Divisible Subset

Given a set of distinct positive integers, 
find the largest subset such that every pair (Si, Sj) 
of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:
Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)

Example 2:
Input: [1,2,4,8]
Output: [1,2,4,8]
*/

class largestDivisibleSubset368
{
public:
  // idea, store the size of largest divisible subset ending with nums[i]
  // we can recursively calculate that for every nums[i]
  std::vector<int> solve(std::vector<int>& nums) {
    int N = nums.size();
    if (N == 0) return {};

    // first sort the array
    std::sort(nums.begin(), nums.end());

    
    // store the count of largest divisible subset end with nums[i] 
    std::vector<int> divCount(N, 1);

    // store the prev elem of nums[i] in the largest sivisible subest
    // end with nums[i]
    std::vector<int> prevInd(N, -1);

    int indMax = 0;  // record the larest subset

    for (int i=0; i<N; ++i) {

      for (int j = i-1; j>=0; --j) 
        if (nums[i]%nums[j] == 0)
          if (divCount[j] + 1 > divCount[i]) {
            divCount[i] = divCount[j] + 1;
            prevInd[i] = j;
          }
           
      if (divCount[i] > divCount[indMax])  
        indMax = i;   

    }

    std::vector<int> res;
    res.push_back(nums[indMax]);
    int ip = prevInd[indMax];
    while (ip >= 0) {
      res.push_back(nums[ip]);
      ip = prevInd[ip];
    }

    return res;

  }


  void test()
  {
    std::vector<int> nums;
    nums = {1,2,4,8};
    std::cout << "input array : ";
    print_data(nums);
    std::cout << "output largest div subset :";
    print_data(solve(nums));
    nums = {1,2,3};
     std::cout << "input array : ";
    print_data(nums);
    std::cout << "output largest div subset :";
    print_data(solve(nums));


  }




};
