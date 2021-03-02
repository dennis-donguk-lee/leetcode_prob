#include <vector>

class Solution {
public:
  int numTeams(std::vector<int>& rating) {
    int ct = 0;

    for (int i = 1; i < rating.size()-1; ++i)
    {
      int less[2] = {}; int greater[2] = {};

      for (int j = 0; j < rating.size(); ++j)
      {
        if (rating.at(i) < rating.at(j)) {
          ++less[j > i];
        }
        if (rating.at(i) > rating.at(j)) {
          ++greater[j > i];
        }
      }

      ct += less[0] * greater[1] + less[1] * greater[0];
    }

    return ct;
  }
};
