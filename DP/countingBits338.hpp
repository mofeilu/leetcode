/*Given a non negative integer number num. 
For every numbers i in the range 0 ≤ i ≤ num 
calculate the number of 1's in their binary representation and 
return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time 
O(n*sizeof(integer)). But can you do it in linear time O(n) 
/possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like 
__builtin_popcount in c++ or in any other language.*/


/*idea:  when mult by 2, the number of 1 in binary rep does not change,
when mult by 2 + 1, the number of 1 in binary rep increase by 1
so we have the following recursion:

r0: 0
r1: 1
r2: 2              3
r3: 4      5       6        7  
r4: 8  9   10  11  12  13   14    15 

round n will ramp up to number 2^n - 1

*/
#include "utils.hpp"

class countingBits338
{

public:

 std::vector<int> solve(int num) {

   std::vector<int> res(num+1, 0);  // 0 to num
   
   int istart = 0;
   int iend = 0;
   while (true) {
     for (int i = istart; i<=iend; ++i) {

       if (2*i > num)
         return res;
       
       res[i*2] = res[i];
       
       if (2*i + 1 > num)
         return res;
      
       res[2*i+1] = res[i] + 1;
     
     }

     istart = iend + 1;
     iend = iend*2 + 1;
   }

   return res;
 }


 void test() 
 {
  int num = 2;
  std::cout << "input is : " << num << ", output is :" ;
  print_data(solve(num));

  num = 5;
  std::cout << "input is : " << num << ", output is :" ;
  print_data(solve(num));

  num = 32;
  std::cout << "input is : " << num << ", output is :" ;
  print_data(solve(num));


  num = 60;
  std::cout << "input is : " << num << ", output is :" ;
  print_data(solve(num));


  num = 63;
  std::cout << "input is : " << num << ", output is :" ;
  print_data(solve(num));

 }



};
