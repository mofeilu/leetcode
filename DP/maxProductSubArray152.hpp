/*Given an integer array nums, find the contiguous 
subarray within an array (containing at least one number) 
which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.*/
#include <math.h>

class maxProductSubArray152
{

public:
// calculate the max postive and negtive product that end at position i, if could not 
// find, return 0
void calMaxPosNegProd(std::vector<int>& nums, int i, std::vector<int> & maxPos, 
	std::vector<int> & maxNeg)
{
	if (i == 0) {
    if (nums[i] > 0)
       maxPos[i] = nums[i];
    else if (nums[i] < 0) 
       maxNeg[i] = nums[i]; 		
		return;
	} 


	calMaxPosNegProd(nums, i-1, maxPos, maxNeg);
   
  if (nums[i] > 0) {
    maxPos[i] = std::max(nums[i]*maxPos[i-1], nums[i]);
    maxNeg[i] = nums[i]*maxNeg[i-1];
  } else if (nums[i] < 0){
      maxNeg[i] = std::min(nums[i]*maxPos[i-1], nums[i]);	
      maxPos[i] = maxNeg[i-1] * nums[i];
  } 

}



int solve(std::vector<int>& nums) {
    // exclude the situation that there's only 1 elem
    if (nums.size() == 1) return nums[0];

    std::vector<int> maxPos(nums.size(), 0);
    std::vector<int> maxNeg(nums.size(), 0);
    calMaxPosNegProd(nums, (int)nums.size()-1, maxPos, maxNeg);
    int res = 0;
    for (int i=0; i<maxPos.size(); ++i)
      if (maxPos[i] > res) res = maxPos[i];
    // when there's at least two elem, res is illegal
    // exclude the situation that there's only 1 negtive elem in nums 
    return res; 
    
}


void test()
{
  std::vector<int> nums;
  nums = {2,3,-2,4};
  std::cout << "input is ";
  print_data(nums);
  std::cout << "output is " << solve(nums) << std::endl;
  nums = {-2,0,-1};
  std::cout << "input is ";
  print_data(nums);
  std::cout << "output is " << solve(nums) << std::endl;


}






};
