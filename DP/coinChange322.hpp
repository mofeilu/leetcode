/*
322. Coin Change
You are given coins of different denominations 
and a total amount of money amount. 
Write a function to compute the fewest number of coins 
that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, 
return -1.

Example 1:
Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
*/

class coinChange322
{
  public:
    // find the best comb for amount = i, store in minNum
    // this is relatively slow
    void findMinComb(std::vector<int>& coins, int i, std::vector<int>& minNum)
    {
      if (i==0) {minNum[i] = 0; return;}
      findMinComb(coins, i-1, minNum);
      minNum[i] = INT_MAX;
      for (int k=0; k<coins.size(); ++k) {
         int j = i - coins[k];
         if (j > 0) {
           if (minNum[j] != -1 && minNum[j] + 1 < minNum[i])
             minNum[i] = minNum[j] + 1;
         } else if (j == 0) {
           minNum[i] = 1;
         }  
      }
      if (minNum[i] == INT_MAX)
        minNum[i] = -1;

    }
   

    int solve(std::vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        std::vector<int> minNum(amount+1, -1);
        findMinComb(coins, amount, minNum);
        return minNum[amount];
    }
    

     // this is faster
    int solve1(std::vector<int>& coins, int amount) {
        if (amount < 0) return -1;

        std::vector<int> minNum(amount+1, -1);
        minNum[0] = 0;
        for (int i=0; i<minNum.size(); ++i) {
          for (int k=0; k<coins.size(); ++k) {
             int j = minNum[i] + coins[k];
             if (j )
             if (minNum[j] == -1)
               minNum[j] = minNum[i] +1;
             else
               minNum[j] = std::min(minNum[j], minNum[i]+1);
           }
        }

         return minNum[amount];
    }

    void test()
    {
      std::vector<int> coins;
      int amount;

      coins = {1, 2, 5};  amount = 11;
      std::cout << "coins: "; print_data(coins);
      std::cout << "amount = " << amount << ", " << " out = " << solve1(coins, amount) << std::endl;
      coins = {1};  amount = 0;
       std::cout << "coins: "; print_data(coins);
      std::cout << "amount = " << amount << ", " << " out = " << solve1(coins, amount) << std::endl;
    }




};
