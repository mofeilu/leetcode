/*839. Similar String Groups
Two strings X and Y are similar if we can swap two letters 
(in different positions) of X, so that it equals Y.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), 
and "rats" and "arts" are similar, 
but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: 
{"tars", "rats", "arts"} and {"star"}.  
Notice that "tars" and "arts" are in the same group 
even though they are not similar.  Formally, each group 
is such that a word is in the group if and only if 
it is similar to at least one other word in the group.

We are given a list A of strings.  
Every string in A is an anagram of every other string in A.  
How many groups are there?

Example 1:
Input: ["tars","rats","arts","star"]
Output: 2
Note:

A.length <= 2000
A[i].length <= 1000
A.length * A[i].length <= 20000
All words in A consist of lowercase letters only.
All words in A have the same length and are anagrams of each other.
The judging time limit has been increased for this question.
*/

using namespace std;

// this is a union find problem,
// we can first construct the connectivity graph
// then find the number of components
class SimilarStringGroups839 {

public:
  // there can be at most two letter different
  bool isSimilar (string const & a, string const & b) {
    int count = 0;
    for (int i=0; i<a.size(); ++i)
       if (a[i] != b[i]) 
         if (++count>2) 
           return false;
    return true;     
  }


  void DFS(int i, vector<unordered_set<int> > & graph, 
      vector<bool> & visited)
  {
     if (visited[i]) return;
     visited[i] = true;
     for (int j : graph[i])
       DFS(j,graph, visited);
  }

  /// this exceed memory limit for large set
  int solve(vector<string>& A) {
     int N = A.size();
     vector<unordered_set<int> > graph(N);
     for (int i=0; i<N; ++i)
       for (int j=i+1; j<N; ++j)
          if (isSimilar(A[i], A[j])) {
            graph[i].insert(j);
            graph[j].insert(i);
          }

     int res = 0;
     vector<bool> visited(N, false);
     for (int i=0; i<N; ++i) {
       if (visited[i]) continue;
       DFS(i, graph,visited);
       res++;
     }

     return res;

  }

  void test()
  {
    vector<string> A;
    A = {"tars","rats","arts","star"};

    cout << "input strings :\n";
    print_data(A);
    cout << "number of group : " << solve(A) << endl;

  }

};
