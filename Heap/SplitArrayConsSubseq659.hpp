/*659. Split Array into Consecutive Subsequences
You are given an integer array sorted in ascending order 
(may contain duplicates), you need to split them into several 
subsequences, where each subsequences consist of at least 3 
consecutive integers. Return whether you can make such a split.

Example 1:
Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5

Example 2:
Input: [1,2,3,3,4,4,5,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5

Example 3:
Input: [1,2,3,4,4,5]
Output: False
Note:
The length of the input is in range of [1, 10000]
*/


class SplitArrayConsSubseq659 {

public:
  // basic idea: we iterate each number in nums, in order for the split
  // to be successful, each number should either be able to join existing subsequence
  // or be able to start a new subsequence
  bool solve(vector<int>& nums) {
     unordered_map<int,int> counts;
     for (int x : nums) ++counts[x];

     // first: end num of the subseq, second: number of such subseq
     unordered_map<int, int> subseq; 
     for (int x : nums) {
       if (counts[x] == 0) continue;
       if (subseq[x-1] > 0) { // there's existing seq ended with x-1
          ++subseq[x]; // create new seq
          --subseq[x-1]; // replace old seq
          --counts[x];   // reduce count of x
       } else if (counts[x+1] > 0 && counts[x+2] > 0) {
         ++subseq[x+2];
         --counts[x];
         --counts[x+1];
         --counts[x+2];
       } else {
         return false;
       }
     }

     return true;

  }


  void test()
  {
    vector<int> nums;
    nums = {1,2,3,3,4,5};
    cout << "input array : ";
    print_data(nums);
    cout << (solve(nums) ? "splitable" : "not splitable") << endl;
    
    nums = {1,2,3,3,4,4,5,5};
    cout << "input array : ";
    print_data(nums);
    cout << (solve(nums) ? "splitable" : "not splitable") << endl;
    

    nums = {1,2,4,4 ,5};
    cout << "input array : ";
    print_data(nums);
    cout << (solve(nums) ? "splitable" : "not splitable") << endl;

  }

};
