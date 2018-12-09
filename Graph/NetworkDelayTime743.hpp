/*743. Network Delay Time
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), 
where u is the source node, v is the target node, 
and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. 
How long will it take for all nodes to receive the signal? 
If it is impossible, return -1.

Note:
N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.
*/   

using namespace std;

// note: this is related to the robotics computational route planning
class NetworkDelayTime743 {

public:
  
  // update delay table within the nodes of delay tab
  void updateDelayTimes(int k, int t, unordered_map<int, int> & delayTimes,
    vector<unordered_map<int, int> > & timesFrom)
  {
     if (delayTimes.find(k) == delayTimes.end()) return;  // no update if not in table
     if (t >= delayTimes[k])  return;  // no update if no improvement
     
     delayTimes[k] = t; // update k
     // recursion to update k's neighbors 
     for (auto & it : timesFrom[k])  
       updateDelayTimes(it.first, t+it.second, delayTimes, timesFrom);
  }

  // find new nodes to add
  void updateNodesInFront(unordered_set<int>& nodesInFront, 
    unordered_map<int, int> & delayTimes,
    vector<unordered_map<int, int> > & timesFrom)
  {
     unordered_set<int> nodesInFrontNew;
     // loop over all the nbrs of nodesInFront
     for (int k : nodesInFront)
      for (auto it : timesFrom[k])
        if (delayTimes.find(it.first) == delayTimes.end())
          nodesInFrontNew.insert(it.first);
     
     nodesInFront = nodesInFrontNew;
  }


  int solve(vector<vector<int>>& times, int N, int K) {

    // delay time of revealed nodes so far
    unordered_map<int, int> delayTimes; // empty at beginning

    vector<unordered_map<int, int> > timesTo(N); // time to v from nbr
    vector<unordered_map<int, int> > timesFrom(N);  // time from u to nbr

    // loop over all the edges
    for (int e = 0; e < times.size(); ++e) {
      int u = times[e][0]-1;  // change to 0 based index
      int v = times[e][1]-1;  // change to 0 based index
      int w = times[e][2];
      timesTo[v][u] = w;  //time to v from u
      timesFrom[u][v] = w;  // time from u to v
    }

    delayTimes[K-1] = 0; // the  root
    unordered_set<int> nodesInFront = {K-1};  // 0 based index
    while (delayTimes.size() < N) {
      updateNodesInFront(nodesInFront, delayTimes, timesFrom); // find new nodes in front
      if (nodesInFront.empty()) return -1; // the graph is not connected at some pt
      // add each node to delayTimes Table, and update delayTimes
      for (int x : nodesInFront) {
         delayTimes[x] = INT_MAX; // add node
         int t = INT_MAX;
         for (auto it : timesTo[x]) {
           if (delayTimes.find(it.first) == delayTimes.end()) continue;
           t = min(t, delayTimes[it.first] + it.second);
         }
         updateDelayTimes(x, t, delayTimes,timesFrom);

      }
    }

    // collect results
    int res = 0;
    for (auto it : delayTimes)
      res = max(res, it.second);
    return res;

  }

  void test()
  {
    vector<vector<int> > times;
    int N, K;
   times = {{2,1,1},{2,3,1},{3,4,1}};
   N = 4;
   K = 2;
   std::cout << "edges of network : \n";
   print_data(times);
   std::cout << "number of nodes = " << N << endl;
   std::cout << "starting node : " << K << endl;
   std::cout << "time to cover the whole network : " << solve(times, N, K) << std::endl;


  }

};
