/*323. Number of Connected Components in an Undirected Graph
Given n nodes labeled from 0 to n - 1 and a list of undirected edges 
(each edge is a pair of nodes), write a function to find the number of 
connected components in an undirected graph.

Example 1:
Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4 

Output: 2

Example 2:
Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

Output:  1

Note:
You can assume that no duplicate edges will appear in edges. 
Since all edges are undirected, [0, 1] is the same as [1, 0] 
and thus will not appear together in edges.
*/
	
using namespace std;

class CountComponents323 {

public:
  // peel off one connect component from the graph, if the resulting compnent is not
  // empty, return true, otherwise return false
  bool getOneComp(unordered_map<int, unordered_set<int> > & graph) {
    if (graph.empty()) return false;

    int start = graph.begin()->first;
    unordered_set<int> nodesAdd = {start}; // current iter
    unordered_set<int> nodesToAdd; // next iter
    
    while(true) {
      for (int u : nodesAdd) 
        for (int v : graph[u]){ // nodes to add v is u's nbr
           // remove connection from v to u
          graph[v].erase(u);
          // newly nodes to add should not below to already added nodes
          if (nodesAdd.find(v) == nodesAdd.end())  
            nodesToAdd.insert(v);
        }

      // delete nodes Add from graph
      for (int u : nodesAdd)
        graph.erase(u);
     
      if (nodesToAdd.empty()) break;

      nodesAdd = nodesToAdd;
      nodesToAdd.clear();
    }

    return true;
  }

  // this is kind of slow, method based on peeol of connected components gradually
  int solve(int n, vector<pair<int, int>>& edges) {
    // first construct graph
    unordered_map<int, unordered_set<int> > graph;
    for (int i=0; i<n; ++i)
      graph[i] = {};
    for (int i= 0; i<edges.size(); ++i) {
      graph[edges[i].first].insert(edges[i].second);
      graph[edges[i].second].insert(edges[i].first);
    }

    int count = 0;
    while (getOneComp(graph)) ++count;

    return count;

  }

  //////////////////////////////////////////////////////////////////////////////////////
  void DFS(int i, unordered_map<int, unordered_set<int> > & graph,
    vector<bool> & visited)
  { 
    visited[i] = true;
    for (int j : graph[i])
      if (!visited[j])
        DFS(j, graph, visited);
  }

  // method based on DFS, faster
  int solve1(int n, vector<pair<int, int>>& edges) {
    // first construct graph
    unordered_map<int, unordered_set<int> > graph;
    for (int i=0; i<n; ++i)
      graph[i] = {};
    for (int i= 0; i<edges.size(); ++i) {
      graph[edges[i].first].insert(edges[i].second);
      graph[edges[i].second].insert(edges[i].first);
    }

    std::vector<bool> visited(n, false);
    int count = 0;
    for (int i=0; i<n; ++i)
      if (!visited[i]) {
        DFS(i, graph, visited);
        ++count;
      }
    return count;

  }


  void test()
  {
    int n; vector<pair<int,int>> edges;
    n = 5;
    edges = {make_pair(0, 1), make_pair(1, 2), make_pair(3, 4)};
    std::cout << "# of nodes : " << n << endl;
    std::cout << "graph is : \n";
    print_data(edges);
    std::cout << "# of connected components : " << solve1(n, edges) << endl;

    n = 5;
    edges = {make_pair(0, 1), make_pair(1, 2), make_pair(2, 3), make_pair(3, 4)};
    std::cout << "# of nodes : " << n << endl;
    std::cout << "graph is : \n";
    print_data(edges);
    std::cout << "# of connected components : " << solve1(n, edges) << endl;

  }

};
