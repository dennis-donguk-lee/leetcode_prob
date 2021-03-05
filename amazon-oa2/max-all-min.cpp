// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
#include <iostream>
#include <queue>
#include <vector>

int maxOfAllMin(
  int numComputer, std::vector<int> hardDiskSpace,int segmentLength) {

  std::priority_queue<int> mins;

  for (int i = 0; i < numComputer - segmentLength; ++i) {

    std::vector<int>::iterator atMin
      = std::min_element(
        hardDiskSpace.begin() + i,
        hardDiskSpace.begin() + i + segmentLength - 1);

    mins.push(*atMin);
  }

  return mins.top();

}
// FUNCTION SIGNATURE ENDS

