/*There are n bulbs that are initially off. 
You first turn on all the bulbs. 
Then, you turn off every second bulb. 
On the third round, you toggle every third bulb 
(turning on if it's off or turning off if it's on). 
For the i-th round, you toggle every i bulb. 
For the n-th round, you only toggle the last bulb. 
Find how many bulbs are on after n rounds.

Example:

Input: 3
Output: 1 
Explanation: 
At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.*/

class BulbSwitch319
{
  public:

    // note this is too slow
  	int solve(int n) {

      std::vector<bool> res(n, false);
      for (int i=0; i<n; ++i) {
        for (int j=i; j<n; j += i+1)
          res[j] = !(res[j]);
      }


      int stilOn = 0;
      for (int i=0; i<n; ++i)
        if (res[i]) stilOn++;
      return stilOn;

  	}

    // this is a mathematically solution
    // observe that only bulb i which is a square number
    // would stay on after all the switches.
    // the mathematically prove is like this:
    // the number of swithes bulb x experiences is equal 
    // to the number of factors x have.
    // we can assume x have prime number factorization:
    // x = p1^n1 * p2^n2 * p3^n3 * .... pk^nk
    // then the number of factors x have is simply:
    // N = (1+n1)*(1+n2)* ... (1+nk)
    // in order for N to be a odd number (so that bulb wiill stay on)
    // n1, n2, ... nk should all be even number
    // meaning that x is a square number
    int solve1(int n) {

      int count = 0;
      int i = 1;
      while (i*i <= n) {
        i++;
        count++;
      }

      return count;

    }

  	void test()
  	{
  	 int n = 3;
     std::cout << "intput = " << n << std::endl;
     std::cout << "output = " << solve1(n) << std::endl;
  	}



};
