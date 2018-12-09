#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <stack>
#include "utils.hpp"
using namespace std;
#include "ZigZagConversion6.hpp"
#include "LongestCommonPrefix14.hpp"
#include "ReverseWordsInString151.hpp"

string genRand() {
  int res =  rand()%71;
  if (res < 10)
    return  '0' + to_string(res);
  else 
    return to_string(res);
}

string genMegaMillion()
{
  string res;
  for (int i=0; i<6; ++i)
    res += " " + genRand();
  return res;
}

int main()
{
  //ZigZagConversion6 t; t.test();
  //LongestCommonPrefix14 t; t.test();
  //ReverseWordsInString151 t; t.test();

  for (int i=0; i<10; ++i) 
    cout << genMegaMillion() << endl;



}
