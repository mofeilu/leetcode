/*
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.*/
class CountPrime204
{
 public:
   /// this method is just too slow
   int solve(int n) {
   	 if (n <= 2) return 0;
     std::vector<int> prims;
     prims.push_back(2);
     for (int i=3; i<=n; ++i) {
       bool isPrime = true;
     	 for (int j=0; j<prims.size(); ++j)
     	   if (i%prims[j] == 0) {
     	  	 isPrime = false;
     	  	 break;
     		 }

       if (isPrime)
         prims.push_back(i);  

     }
     
     if (prims[(int)prims.size()-1] == n) // the last push should not cound
       return (int)prims.size() - 1;
     else
       return prims.size();

   }


   void test() {
    int n = 10;
    std::cout << "input num is " << n <<", " << "# of prime less than is " << solve(n) << std::endl;
    n = 3;
    std::cout << "input num is " << n <<", " << "# of prime less than is " << solve(n) << std::endl;
   }


};
