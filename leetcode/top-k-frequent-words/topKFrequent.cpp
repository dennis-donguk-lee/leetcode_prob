#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

// Try to solve it in O(n log k) time and O(n) extra space.
class Solution {
public:
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

    std::vector<std::pair<std::string, int>> sortedWords;
    // O(n); O(n)
    for (auto const& [word, ct] : wordCtMap) {
      sortedWords.push_back(std::make_pair(word, ct));
    }

    // comp by ct, then alphabetical
    auto comp = [](
      std::pair<std::string, int> const x, 
      std::pair<std::string, int> const y) {
      if (x.second == y.second) { return x.first.compare(y.first) < 0; }
      return x.second > y.second;
    };
    // O(n log n);
    std::sort(sortedWords.begin(), sortedWords.end(), comp);

    // for k
    std::vector<std::string> res;
    // O(k); O(k)
    for (int i = 0; i < k; ++i) { res.push_back(sortedWords[i].first); }

    return res;
  }
};

