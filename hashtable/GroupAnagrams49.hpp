/*49. Group Anagrams
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

class GroupAnagrams49
{
public:
  /// the idea is simple, we sort the char in string to make a unique key
  std::vector<std::vector<std::string>> 
  solve(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string> > groups;
    for (int i=0; i<strs.size(); ++i) {
      std::string key = strs[i];
      std::sort(key.begin(), key.end());
      groups[key].push_back(strs[i]);
    }

    std::vector<std::vector<std::string>>  res;
    for (auto it : groups)
      res.push_back(it.second);
    return res;

  }

  void test()
  {
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::cout << "input strs : ";
    print_data(strs);

    std::cout << "grouped anagrams: \n";
    print_data(solve(strs));


  }

};
