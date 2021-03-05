#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) {

    std::sort(boxTypes.begin(), boxTypes.end(), greater());

    int ct = 0, szLeft = truckSize;
    for (std::vector<int> box_type : boxTypes) {
      int szAfterLoad = szLeft - box_type[0];
      if (szAfterLoad <= 0) {
        ct += szLeft * box_type[1];
        break;
      }

      ct += box_type[0] * box_type[1];
      szLeft -= box_type[0];
    }

    return ct;
  }

private:
  struct greater {
    template<class T>
    bool operator()(T const &a, T const &b) const { return a[1] > b[1]; }
  };
};
