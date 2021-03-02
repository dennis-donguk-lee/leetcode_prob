#include <iostream>
#include <vector>

class Solution {
public:
  int numTeams(std::vector<int>& rating) {
    int ct = 0;

    // right order
    for (int i = 0; i < rating.size() - 2; ++i) {
      int first = rating.at(i);

      for (int j = i + 1; j < rating.size() - 1; ++j) {
        int second = rating.at(j);
        if (second < first) {
          continue;
        }

        for (int k = j + 1; k < rating.size(); ++k) {
          int third = rating.at(k);
          if (third < second) {
            continue;
          }
          //std::cout << first << second << third << std::endl;
          ++ct;
        }
      }
    }

    // reverse order
    for (int i = rating.size() - 1; i >= 2; --i) {
      int first = rating.at(i);

      for (int j = i - 1; j >= 1; --j) {
        int second = rating.at(j);
        if (second < first) {
          continue;
        }

        for (int k = j - 1; k >= 0; --k) {
          int third = rating.at(k);
          if (third < second) {
            continue;
          }
          //std::cout << first << second << third << std::endl;
          ++ct;
        }
      }
    }

    return ct;

  }
};
