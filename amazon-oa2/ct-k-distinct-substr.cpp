// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION 
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
#include <set>
#include <string>

int countKDistinctSubstrings(std::string inputString, int num) {

  int sz = inputString.length();
  int res = 0;
  int ct[26];

  for (int i = 0; i < sz; ++i) {

    memset(ct, 0, sizeof(ct));
    int numDist = 0;

    for (int j = i; j < sz; ++j) {
      if (ct[inputString.at(j) - 'a']++ == 0) ++numDist;
      if (numDist == num) ++res;
      if (numDist > num) break;
    }
  }

  return res;

}
// FUNCTION SIGNATURE ENDS

