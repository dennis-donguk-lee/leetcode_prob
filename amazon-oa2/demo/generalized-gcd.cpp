#include <algorithm>
#include <functional>
#include <set>

// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
using namespace std;
int generalizedGCD(int* arr,int len) {

  set<int, greater<>> diffs;
  for (int i = 0; i < len-1; ++i) {
    diffs.insert(arr[i + 1] - arr[i]);
  }

  bool isGCD = true;
  for (auto diff : diffs) {
    for (int i = 0; i < len; ++i) {
      if (arr[i] % diff) {
        isGCD = false;
        break;
      }
    }

    if (isGCD) {
      return diff;
    }
    isGCD = true;
  }

  return 1;
}
// FUNCTION SIGNATURE ENDS

