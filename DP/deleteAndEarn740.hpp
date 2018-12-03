/*740. Delete and Earn
Given an array nums of integers, 
you can perform operations on the array.

In each operation, you pick any nums[i] 
and delete it to earn nums[i] points. 
After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

You start with 0 points. 
Return the maximum number of points you can earn by applying such operations.

Example 1:
Input: nums = [3, 4, 2]
Output: 6
Explanation: 
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.

Example 2:
Input: nums = [2, 2, 3, 3, 3, 4]
Output: 9
Explanation: 
Delete 3 to earn 3 points, deleting both 2's and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.
Note:

The length of nums is at most 20000.
Each element nums[i] is an integer in the range [1, 10000].
*/
#include <algorithm>
class deleteAndEarn740
{
public:

  int solve(std::vector<int>& nums) {
 
        
  }

  void test() 
  {
    std::vector<int> nums = {2, 2, 3, 3, 3, 4};
    std::cout << "input vector : ";
    print_data(nums);
    std::cout << "earn = " << solve(nums) << std::endl;
    nums = {3, 4, 2};
    std::cout << "input vector : ";
    print_data(nums);
    std::cout << "earn = " << solve(nums) << std::endl;
    nums = {1,8,5,9,6,9,4,1,7,3,3,6,3,3,8,2,6,3,2,2,1,2,9,8,7,1,1,10,6,7,3,9,6,10,5,4,10,1,6,7,4,7,4,1,9,5,1,5,7,5};
    std::cout << "input vector : ";
    print_data(nums);
    std::cout << "earn = " << solve(nums) << std::endl;
  }


};
