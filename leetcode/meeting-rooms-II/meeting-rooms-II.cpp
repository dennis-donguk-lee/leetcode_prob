//Given an array of meeting time intervals intervals
//where intervals[i] = [starti, endi], 
// return the minimum number of conference rooms required.
// 
//Example 1:
//Input: intervals = [[0,30],[5,10],[15,20]]
//Output: 2
//
//Example 2:
//Input: intervals = [[7,10],[2,4]]
//Output: 1
// 
//Constraints:
//    1 <= intervals.length <= 10^4
//    0 <= starti < endi <= 10^6

#include <vector>
#include <queue>

class Solution {
public:
  int minMeetingRooms(std::vector<std::vector<int>>& intervals) {

    // sort intervals w/ start time (could sort the passed param to save space)
    // Using lambda to compare elements.
    auto cmp = [](std::vector<int> left, std::vector<int> right) {
      if (left[0] == right[0]) { return left[1] < right[1]; }
      return left[0] > right[0];
    };
    std::priority_queue<
      std::vector<int> , std::vector<std::vector<int>>, decltype(cmp) >
        sortedIntervals(cmp);
    for (std::vector<int> interval : intervals) {
      sortedIntervals.push(interval);
    }

    // min-heap for end times
    std::priority_queue< int, std::vector<int>, std::greater<> > sortedEndTimes;

    // rm scheduling by checking earliest end time
    while (!sortedIntervals.empty()) {
      int currStart = sortedIntervals.top()[0];
      int currEnd = sortedIntervals.top()[1];
      sortedIntervals.pop();

      if (sortedEndTimes.empty()) { sortedEndTimes.push(currEnd); continue; }

      if (currStart >= sortedEndTimes.top()) { sortedEndTimes.pop(); }
      sortedEndTimes.push(currEnd);
    }

    // return alloc'ed meeting rms
    return sortedEndTimes.size();
  }
};

