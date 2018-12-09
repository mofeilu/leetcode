/*151. Reverse Words in a String
Given an input string, reverse the string word by word.

Example:  
Input: "the sky is blue",
Output: "blue is sky the".
Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, 
your reversed string should not contain leading or trailing 
spaces. You need to reduce multiple spaces between two words 
to a single space in the reversed string. 
Follow up: For C programmers, 
try to solve it in-place in O(1) space.
*/

class ReverseWordsInString151 {

public:
  // note: here we use a stack to reverse the words
  // for O(1) space in place solution, we can iterate 
  // backwords, and gradually put each word at end 
  void solve(string &s) {


    stack<string> words;
    int i, j;  // i, j is the begin and end pos of a word
    i = 0;
    while (i < s.size()) {
      while (i < s.size() && s[i] == ' ') ++i; 
      j = i; 
      while (j < s.size() && s[j] != ' ') ++j;
      if (j-i>0) words.push(s.substr(i,j-i));
      i = j;
    }
     
    i = 0;
    while (!words.empty()) {
      string word = words.top();
      cout << "word = " << word << endl;
      words.pop();
      s.replace(i, word.size(), word);
      i += word.size(); 
      if (words.empty()) break; // we do not need last empty space
      s[i] = ' ';
      ++i;
    }

    s = s.substr(0,i);
  }

  void test()
  {
    string str;
    str = "the sky is blue";
    cout << "input str : " << str << endl;
    solve(str);
    cout << "reversed str : " << str << endl;

    str = "   the sky is blue     ";
    cout << "input str : " << str << endl;
    solve(str);
    cout << "reversed str : " << str << endl;

  }

};
