#include <algorithm>
#include <functional>
#include <set>

// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }

  return gcd(b, a%b);
}

int generalizedGCD(int* arr,int len) {
  int res = arr[0];
  for (int i = 1; i < len; ++i) {
    res = gcd(arr[i], res);

    if (res == 1) {
      return 1;
    }
  }

  return res;
}
// FUNCTION SIGNATURE ENDS

