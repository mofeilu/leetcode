/*313. Super Ugly Number
Write a program to find the nth super ugly number.
Super ugly numbers are positive numbers whose all prime factors 
are in the given prime list primes of size k.

Example:
Input: n = 12, primes = [2,7,13,19]
Output: 32 
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] 
is the sequence of the first 12 super ugly numbers 
given primes = [2,7,13,19] of size 4.

Note:
1 is a super ugly number for any given primes.
The given numbers in primes are in ascending order.
0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
The nth super ugly number is guaranteed to fit in a 32-bit 
signed integer.
*/

class SuperUglyNumber313 {

public:
  // this problem is a generalization of UglyNumber problem, with more
  // prime factors 
  int solve(int n, vector<int>& primes) {
    int Np = primes.size();
    // pair<int,int>: first is number, second is the index in primes
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    
    vector<int> res; // ugly numbers
    res.push_back(1);  // first ugly number

    // index[i]: the index to res, be multiplied by primes[i]
    vector<int> indx(Np, 0); // initially, all point to index 0
   
    for (int i=0; i<Np; ++i) 
      pq.push(make_pair(primes[i], i));
    

    for (int m=1; m<n; ++m) {// we need to find the remaining n-1 ugly number 
        int minVal = pq.top().first;
        res.push_back(minVal);
        while (pq.top().first == minVal) {
          int indxPrime = pq.top().second;
          ++indx[indxPrime];
          int nextVal = res[indx[indxPrime]] * primes[indxPrime];
          pq.pop(); pq.push(make_pair(nextVal, indxPrime));
        }
    }
    return res.back();

  }

  void test()
  {
    vector<int> primes; int n;
    primes = {2,7,13,19}; n = 12;
    cout << "primes pool : ";
    print_data(primes);
    cout << "the " << n << "th ugly number is " << solve(n,primes) << endl;


  }

};
