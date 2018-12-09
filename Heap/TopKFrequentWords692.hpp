/*692. Top K Frequent Words
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. 
If two words have the same frequency, then the word with the lower 
alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
*/


class TopKFrequentWords692 {

public:
  // idea : we use hashtable to record the frequency
  vector<string> solve(vector<string>& words, int k) {
    map<string, int> count;
    for (auto & word : words) ++count[word];
    
    // note: here we use a map, another way is to use priority queue
    // make sure you design the that comparator prefer large count and small lexical word
    map<int, vector<string> > freq;
    for (auto & it : count)
      freq[it.second].push_back(it.first);
    int i = 0;
    vector<string> res;
    auto it = freq.end(); // we go backwords since we want most frequent
    while (it != freq.begin()) {  
      --it;
      for (string word : it->second) {
        res.push_back(word);
        ++i;
        if (i == k)
          return res;
      }
    }
    
  }

  void test()
  {
    vector<string> words; int k;
    words = {"i", "love", "leetcode", "i", "love", "coding"};
    k = 2;
    cout << "all words : \n";
    print_data(words);
    cout << "the " << k << " most frequenct words : \n";
    print_data(solve(words,k));

  }

};
