/*767. Reorganize String
Given a string S, check if the letters can be rearranged 
so that two characters that are adjacent to each other 
are not the same.

If possible, output any possible result.  
If not possible, return the empty string.

Example 1:
Input: S = "aab"
Output: "aba"

Example 2:
Input: S = "aaab"
Output: ""

Note:
S will consist of lowercase letters and 
have length in range [1, 500].
*/ 

class ReorganizeString767 {

public:

  // idea: we maintain a heap (priority queue) about number of each remaining characters
  //  for each iteration, we append the char with largest number that are not the same 
  //  as the back of the string, and adjust the char number correspondingly.
  //  we do this until the heap is empty
  string solve(string S) {
    unordered_map<char, int> mp;
    for (char c : S) ++mp[c];
   
    priority_queue<pair<int,char>, vector<pair<int,char> > > pq;
    for (auto it : mp)
      pq.push(make_pair(it.second,it.first));


    string res;
    pair<int, char> tmp = pq.top();
    pq.pop();
    res += tmp.second;
    tmp.first -= 1;
    if (tmp.first > 0) pq.push(tmp); // put back

    while (!pq.empty()) {
      if (pq.top().second != res.back()) {
        pair<int, char> tmp = pq.top();
        pq.pop();
        res += tmp.second;
        --tmp.first;
        if (tmp.first > 0) pq.push(tmp); // put back
      } else {
        pair<int, char> tmp1 = pq.top(); pq.pop();
        if (pq.empty()) return "";  // we can not make it
        pair<int, char> tmp2 = pq.top(); pq.pop();
        res += tmp2.second;
        --tmp2.first;
        if (tmp2.first > 0) pq.push(tmp2); // put back
        pq.push(tmp1);
      }
    }

    return res;
  }

  void test()
  {
    vector<string> strs = {"aab", "aaab"};
    for (string str : strs) {
      cout << "input str : " << str << endl;
      cout << "rearranged str : " << solve(str) << endl;
    }

  }

};
