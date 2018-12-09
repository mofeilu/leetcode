/*71. Simplify Path

Given an absolute path for a file (Unix-style), simplify it. 
For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
path = "/a/../../b/../c//.//", => "/c"
path = "/a//b////c/d//././/..", => "/a/b/c"

In a UNIX-style file system, a period ('.') 
refers to the current directory, so it can be ignored 
in a simplified path. Additionally, a double period ("..") 
moves up a directory, so it cancels out whatever the last 
directory was. For more information, 
look here: https://en.wikipedia.org/wiki/Path_(computing)#Unix_style

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/


class SimplifyPath71 {

public:
  // tokenize use "/"
  vector<string> tokenize(string const & str)
  { 
    vector<string> res;
    int start = 1; // exclude the first '/''
    for (int i=1; i<str.size(); ++i) {
      if (str[i] == '/') {
        string token = str.substr(start, i-start);
        start = i+1;
        if (!token.empty())
          res.push_back(token);
      }
    }
    
    if (start < str.size())  // push the last token
      res.push_back(str.substr(start));
    
    return res;
  }

  string solve(string path) {
    vector<string> dirs = tokenize(path);
    stack<string> stk;
    for (string dir : dirs) {
      if (dir != "." && dir != "..")
        stk.push(dir);
      else if (dir == ".." && !stk.empty())
        stk.pop();
    }

    // summarize path, add necessary "/"
    string res;
    while (!stk.empty()) {
       res.insert(0, "/" + stk.top());
       stk.pop();
    }
    if (res.empty()) res = "/";
    return res;

  }

  void test()
  {
    vector<string> paths;

    paths = {"/home/", "/a/./b/../../c/", "/a/../../b/../c//.//",
             "/a//b////c/d//././/.."};
    for (string path : paths) {
      cout << "input path: " << path << endl;
      //cout << "token : ";
      //print_data(tokenize(path));
      cout << "simplified path :" << solve(path) << endl;
    }

  }

};
