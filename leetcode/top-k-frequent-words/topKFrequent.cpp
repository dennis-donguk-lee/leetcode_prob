#include <queue>
#include <vector>
#include <string>
#include <unordered_map>

// Try to solve it in O(n log k) time and O(n) extra space.
class Solution {
public:
  // O(n log k), O(n)
  std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k)
  {
    // unordered map
    std::unordered_map<std::string, int> wordCtMap;
    // for words into map
    // O(n); O(n)
    for (const auto& word : words) {
      if (wordCtMap.find(word) == wordCtMap.end()) { wordCtMap[word] = 1; }
      else { ++wordCtMap[word]; }
    }

    // comp by ct, then alphabetical
    auto comp = [](
      std::pair<std::string, int> const x, 
      std::pair<std::string, int> const y) {
      if (x.second == y.second) { return x.first.compare(y.first) < 0; }
      return x.second > y.second;
    };

    std::priority_queue<
      std::pair<std::string, int>,
      std::vector<std::pair<std::string, int>>,
      decltype(comp)
    > sortedWords(comp);
    // O(n log k); O(k)
    for (auto const& [word, ct] : wordCtMap) {
      sortedWords.push(std::make_pair(word, ct));
      if (sortedWords.size() > k) { sortedWords.pop(); }
    }

    std::vector<std::string> res;
    // O(k); O(k)
    for (; !sortedWords.empty(); sortedWords.pop()) {
      res.insert(res.begin(), sortedWords.top().first);
    }

    return res;
  }
};

