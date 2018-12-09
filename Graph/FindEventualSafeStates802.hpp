/*802. Find Eventual Safe States
In a directed graph, we start at some node and every turn, 
walk along a directed edge of the graph.  
If we reach a node that is terminal 
(that is, it has no outgoing directed edges), we stop.

Now, say our starting node is eventually safe if and only if 
we must eventually walk to a terminal node.  
More specifically, there exists a natural number K so that 
for any choice of where to walk, we must have stopped at a terminal 
node in less than K steps.

Which nodes are eventually safe?  Return them as an array in sorted 
order.

The directed graph has N nodes with labels 0, 1, ..., N-1, 
where N is the length of graph.  
The graph is given in the following form: graph[i] is a 
list of labels j such that (i, j) is a directed edge of the graph.

Example:
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]

Note:
graph will have length at most 10000.
The number of edges in the graph will not exceed 32000.
Each graph[i] will be a sorted list of different integers, 
chosen within the range [0, graph.length - 1].*/

using namespace std;

class FindEventualSafeStates802 {

public:
  // idea, a node is safe if and only if every outbound path
  // from it ended up in a terminal node, we can classify the status
  // of node as unvisited (0), unsafe(1), safe (2). use DFS to traverse
  // starting from certain node, if all path ended up safe, this node
  // is safe

  int DFS(int i, vector<vector<int>>& graph, vector<int> & status)
  {
    if (status[i] != 0) return status[i];

    status[i] = 1; // init as unsafe
    for (int k=0; k<graph[i].size(); ++k)
      if (DFS(graph[i][k], graph, status) == 1) 
        return 1;

    status[i] = 2;
    return 2;  
  } 

  vector<int> solve(vector<vector<int>>& graph) {

     int N = graph.size();
     std::vector<int> states(N, 0); // all unvisited at beginning

     std::vector<int> res;
     for (int i= 0; i<N; ++i)
       if (DFS(i, graph, states) == 2)
          res.push_back(i);

     return res;   
  }

  void test()
  {
    vector<vector<int> > graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    std::cout << "input graph : \n";
    print_data(graph);

    std::cout <<"safe nodes : ";
    print_data(solve(graph)); 


  }

};

/*
class Solution {
    bool dfs(vector<vector<int>>& graph, vector<int>& states, int cur) {
        if (states[cur] == 1) {
            return false;
        }
        if (states[cur] == 2) {
            return true;
        }
        states[cur] = 1;
        for (auto& nei : graph[cur]) {
            if (!dfs(graph, states, nei)) {
                return false;
            }
        }
        states[cur] = 2;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> states(graph.size(), 0);
        for (int i = 0; i < graph.size(); ++i) {
            dfs(graph, states, i);
        }
        vector<int> rets;
        for (int i = 0; i < states.size(); ++i) {
            if (states[i] == 2) {
                rets.push_back(i);
            }
        }
        return rets;
    }
};*/
