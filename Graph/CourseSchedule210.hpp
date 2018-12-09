/*210. Course Schedule II
There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 
you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, 
return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. 
If it is impossible to finish all courses, return an empty array.

Example 1:
Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. 
So the correct course order is [0,1] .

Example 2:
Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. 
To take course 3 you should have finished both courses 1 and 2. 
Both courses 1 and 2 should be taken after you finished course 0. 
So one correct course order is [0,1,2,3]. Another correct 
ordering is [0,2,1,3] .

Note:
The input prerequisites is a graph represented by a list of edges, 
not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/
using namespace std;

// idea: there're actually two parts of this problem: 
// (1) detect if there's any loop in the directed path
// (2) traverse the graph with DFS and always put right brach in front of left branch
class CourseSchedule210
{
public:

 bool DFS(int i, vector<vector<int> > const & graph, vector<bool> & parents,
 	   vector<bool> & visited, vector<int> & order) 
 {
 	order.clear();
 	if (parents[i]) return false;
 	if (visited[i]) return true;
 	parents[i] = true;
 	visited[i] = true;
  order.push_back(i); // root node
 	for (int k=0; k<graph[i].size(); ++k) {
    int j = graph[i][k];
    vector<int> orderTmp;
    if (!DFS(j, graph, parents, visited, orderTmp)) return false;
    order.insert(order.begin()+1, orderTmp.begin(), orderTmp.end()); // we insert new brach right after root node     
 	} 
 	parents[i] = false; // before return modify the parent status
 	return true;
 }

 // the trick here is we maintain both table for visited and parents
 // parents for loop detection, visited for non-redundent traverse
 // also, to keep topological order, in DFS, we always put 
 // right childs in front of left childs
 vector<int> solve(int numCourses, vector<pair<int, int>>& prerequisites) {
 	int N = numCourses;
    vector<vector<int> > graph(N);  // graph[i][k] gives a directed edge from i 
    for (auto it : prerequisites)
    	graph[it.second].push_back(it.first);
    vector<bool> parents(N, false);
    vector<bool> visited(N, false);
    vector<int> res;
   
    for (int i=0; i<N; ++i) {
       if (visited[i]) continue;
       vector<int> order;
       if (!DFS(i, graph, parents, visited, order)) return {};  // DFS fail, return empty array
       res.insert(res.begin(), order.begin(), order.end()); // we always put in front to be saft
    }

    return res;
 }

 void test()
 {
  int numCourses;
  vector<pair<int, int> > pre;
  numCourses= 4;
  pre = {make_pair(1,0),make_pair(2,0),make_pair(3,1),make_pair(3,2)};
  cout << "number of courses : " << numCourses << endl;
  cout << "prerequisites : \n";
  print_data(pre);
  cout << "order : ";
  print_data(solve(numCourses, pre));


  numCourses= 2;
  pre = {make_pair(1,0)};
  cout << "number of courses : " << numCourses << endl;
  cout << "prerequisites : \n";
  print_data(pre);
  cout << "order : ";
  print_data(solve(numCourses, pre));

  numCourses= 2;
  pre = {make_pair(0,1)};
  cout << "number of courses : " << numCourses << endl;
  cout << "prerequisites : \n";
  print_data(pre);
  cout << "order : ";
  print_data(solve(numCourses, pre));



 }


};
