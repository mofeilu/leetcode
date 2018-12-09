/*347. Top K Frequent Elements
Given a non-empty array of integers, return the k most 
frequent elements.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), 
where n is the array's size.
*/

#include <queue>          // std::priority_queue
#include <functional>     // std::greater
#include <utility>        // pair

class TopKFreqElem347
{
public:
   typedef std::pair<int, int> P;  // first is frequency, second is key

  // idea: use a map to maintain frequency, use a vector
  // to store the top K frequent elems and keep updating
  std::vector<int> solve(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    for (int x : nums)
      freq[x]++;

    // use greater as comparitor to keep largest in queue
    std::priority_queue<P, std::vector<P>, std::greater<P> > tops;
    for (auto x : freq) {
      if (tops.size() < k) {  // less than k elems in queue
        tops.push(std::make_pair(x.second, x.first));
      } else if (x.second > tops.top().first) {
        tops.pop();
        tops.push(std::make_pair(x.second, x.first));

      } 

    }

    std::vector<int> res;
    while (!tops.empty()) {
      res.push_back(tops.top().second);
      tops.pop();
    }
    

    return res;

  }


  void test()
  {
    std::vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    std::cout<<"input vec :";
    print_data(nums);
    std::cout<< "most " << k << " frequent elems : ";
    print_data(solve(nums,k));
    nums = {1};
    k = 1;
    std::cout<<"input vec :";
    print_data(nums);
    std::cout<< "most " << k << " frequent elems : ";
    print_data(solve(nums,k));


  }
};
