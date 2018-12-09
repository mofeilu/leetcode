/*496. Next Greater Element I
You are given two arrays (without duplicates) 
nums1 and nums2 where nums1’s elements are subset of nums2. 
Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.

Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.

Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.
*/

class NextGreaterElement496 {

public:
    // this is a simple stack solution, but pretty slow
    vector<int> solve(vector<int>& findNums, vector<int>& nums) {
      
      vector<int> res;
      for (int x : findNums) {
        stack<int> stk;
        for (int i=(int)nums.size()-1; i>=0; --i)
          if (nums[i] > x) stk.push(nums[i]);
          else if (nums[i] == x) 
            res.push_back((stk.empty() ? -1 : stk.top()));
      }
      return res;
    }

    /* this is a fast solution
     loop over nums, keep pushing elem into stack, whenever 
     curr elem > than top of stack, pop stack and record curr
     elem in hash table
     */

    vector<int> solve1(vector<int>& findNums, vector<int>& nums)
    {
      unordered_map<int, int> m;
      stack<int> stk;
      for (int x : nums) {
         while (!stk.empty() && x > stk.top()) {
            m[stk.top()] = x;
            stk.pop();
         }
         stk.push(x);
      }

      vector<int> res;
      for (int x : findNums)
        res.push_back( (m.count(x) > 0 ? m[x] : -1) );
      return res;
    }

    void test()
    {
      vector<int> nums1, nums2;
      nums1 = {4,1,2}; nums2 = {1,3,4,2};
      cout << "nums1 = "; print_data(nums1);
      cout << "nums2 = "; print_data(nums2);
      cout << "res = "; print_data(solve1(nums1,nums2));

      nums1 = {2,4}; nums2 = {1,2,3,4};
      cout << "nums1 = "; print_data(nums1);
      cout << "nums2 = "; print_data(nums2);
      cout << "res = "; print_data(solve1(nums1,nums2));
    }

};



