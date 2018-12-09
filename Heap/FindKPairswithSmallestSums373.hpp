/*373. Find K Pairs with Smallest Sums
You are given two integer arrays nums1 and nums2 sorted in ascending order
 and an integer k.

Define a pair (u,v) which consists of one element from the first array
 and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]] 
Explanation: The first 3 pairs are returned from the sequence: 
             [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:
Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [1,1],[1,1]
Explanation: The first 2 pairs are returned from the sequence: 
             [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

Example 3:
Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [1,3],[2,3]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
*/

class FindKPairswithSmallestSums373 {

public:
  //  this problem is similar to problem superUglynumber
  vector<pair<int, int>> solve(vector<int>& nums1, vector<int>& nums2, int k) {
      int N1 = nums1.size();
      int N2 = nums2.size();
      if (N1 == 0 || N2 == 0) return {};
   
  
     // indxInNums2[i] gives nums1[i] and its current pair in nums2;    
      vector<int> indxInNums2(N1, 0); // initially all to 0th elem of nums2
      
      // pair<int,int> first is sum, second is index in nums1
      priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
      for(int i=0; i<N1; ++i)
        pq.push(make_pair(nums1[i]+nums2[0], i));
      
      vector<pair<int, int>> res;

      for (int m=0; m<k; ++m) {
        int minVal = pq.top().first;
        while (pq.top().first == minVal) {
          int ind1 = pq.top().second;
          int ind2 = indxInNums2[ind1];
          res.push_back(make_pair(nums1[ind1],nums2[ind2]));
          if (res.size() == k) return res;
          pq.pop();
          if (indxInNums2[ind1] < N2-1) {
            ++indxInNums2[ind1];
            int nextVal = nums1[ind1] + nums2[indxInNums2[ind1]];
            pq.push(make_pair(nextVal, ind1));
          }
          if (pq.empty()) return res; // pq is empty means all pairs have been visited
        }
      }

      return res;

  }

  void test()
  {
    vector<int> nums1, nums2;
    int k;

    nums1 = {1,1,2}; 
    nums2 = {1,2,3};
    k = 2;
    cout << "nums1 = ";
    print_data(nums1);
    cout << "nums2 = ";
    print_data(nums2);
    cout << "first " << k << " smallest pairs : ";
    print_data(solve(nums1,nums2,k));

    nums1 = {1,7,11}; 
    nums2 = {2,4,6};
    k = 3;
    cout << "nums1 = ";
    print_data(nums1);
    cout << "nums2 = ";
    print_data(nums2);
    cout << "first " << k << " smallest pairs : ";
    print_data(solve(nums1,nums2,k));


    nums1 = {1,2}; 
    nums2 = {3};
    k = 3;
    cout << "nums1 = ";
    print_data(nums1);
    cout << "nums2 = ";
    print_data(nums2);
    cout << "first " << k << " smallest pairs : ";
    print_data(solve(nums1,nums2,k));
  }

};
