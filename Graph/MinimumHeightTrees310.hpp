/*310. Minimum Height Trees
For a undirected graph with tree characteristics, 
we can choose any node as the root. The result graph is then a rooted tree. 
Among all possible rooted trees, those with minimum height are called 
minimum height trees (MHTs).Given such a graph, write a function to 
find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. 
You will be given the number n and a list of undirected edges 
(each edge is a pair of labels). You can assume that no duplicate edges 
will appear in edges. Since all edges are undirected, [0, 1] is the same as 
[1, 0] and thus will not appear together in edges.

Example 1 :
Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3 

Output: [1]

Example 2 :
Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5 

Output: [3, 4]
Note:

According to the definition of tree on Wikipedia:
“a tree is an undirected graph in which any two vertices 
are connected by exactly one path. In other words, any connected graph 
without simple cycles is a tree.”
The height of a rooted tree is the number of edges on 
the longest downward path between the root and a leaf.*/
using namespace std;

class MinimumHeightTrees310 {
public:
  // we need to exclude parent
  int findDepth(int s, vector<unordered_set<int> > & graph, int parent)
  {
    
    int d = 0;
    for (int nbr : graph[s]) {
      if (nbr == parent) continue;
      d = std::max(d, 1+findDepth(nbr, graph, s));
    }

    return d;
  }

  // this solution is correct but exceed time limit
  vector<int> solve(int n, vector<pair<int, int>>& edges)
  {
    // we need to first construct undirectd graph
    vector<unordered_set<int>> graph(n);
    for (int i=0; i<edges.size(); ++i) {
      graph[edges[i].first].insert(edges[i].second);
      graph[edges[i].second].insert(edges[i].first);
    }

    // find the min depth
    vector<int> depth(n, 0);
    int depthMin = INT_MAX;
    for (int i=0; i<n; ++i) {
      depth[i] = findDepth(i, graph, -1);
      depthMin = min(depthMin, depth[i]);
    }

    vector<int> res;
    for (int i=0; i<n; ++i) 
      if (depth[i] == depthMin) res.push_back(i);
    return res;
  }

  ///////////////////////////// those are for faster calc ////////////////////////////
  int findDepth(int root, vector<unordered_map<int, int> > & graph, int parent) {
    // already calculated
    if (parent >= 0 && graph[root][parent] != -1) return graph[root][parent];
    
    int d = 0;
    for (auto & it : graph[root]) {
      if (it.first == parent) continue;
      d = std::max(d, 1+findDepth(it.first, graph, root));
    }

    if (parent >= 0)
      graph[root][parent] = d;
    return d;
  }

  // faster routine
  vector<int> solve1(int n, vector<pair<int, int>>& edges)
  {
    // we need to first construct undirectd graph, map[i][j]
    // gives the MHT start from i, but exclude the path through neighbor j
    vector<unordered_map<int, int>> graph(n);
    for (int i=0; i<edges.size(); ++i) {
      graph[edges[i].first][edges[i].second] = -1;
      graph[edges[i].second][edges[i].first] = -1;
    }
     
    // find the min depth
    vector<int> depth(n, 0);
    int depthMin = INT_MAX;
    vector<int> res;

    for (int i=0; i<n; ++i) {
      depth[i] = findDepth(i, graph, -1);
      if (depth[i] == depthMin)
        res.push_back(i);
      else if (depth[i] < depthMin) {
        depthMin = depth[i];
        res.clear();
        res.push_back(i);
      }
    }

    return res;
  }

  void test()
  {
    int n;
    vector<pair<int, int> > edges;
    n = 6; 
    edges = {make_pair(0, 3), make_pair(1, 3), make_pair(2, 3), make_pair(4, 3), make_pair(5, 4)};
    std::cout <<"number of nodes of input graph : " << n << endl;
    std::cout<<"edges of input graph : ";
    print_data(edges);
    std::cout << "root of MHT : ";
    print_data(solve1(n,edges));
  }


};
