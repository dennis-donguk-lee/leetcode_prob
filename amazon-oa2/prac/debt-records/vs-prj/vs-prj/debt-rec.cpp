#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <unordered_map>
#include <vector> // vector

bool compareFunction (std::string a, std::string b) {return a<b;} 

std::vector<std::string> debt_records(std::vector<std::vector<std::string>> debts) {
  std::unordered_map<std::string, int> recKeeps;

  for (std::vector<std::vector<std::string>>::value_type dbt : debts) {
    std::string burrower = dbt[0];
    std::string lender = dbt[1];
    int amnt = std::stoi(dbt[2]);

    if (!recKeeps.contains(burrower)) recKeeps[burrower] = -amnt;
    else recKeeps[burrower] = recKeeps[burrower] - amnt;

    if (!recKeeps.contains(lender)) recKeeps[lender] = amnt;
    else recKeeps[lender] = recKeeps[lender] + amnt;
  }

  int min = 9999999;
  for (auto it = recKeeps.begin(); it != recKeeps.end(); ++it) {
    int val = it->second;
    if (val < min) {
      min = val;
    }
  }

  std::vector<std::string> res;
  for (auto it = recKeeps.begin(); it != recKeeps.end(); ++it) {
    if (it->second == min)
      res.push_back(it->first);
  } 

  // todo: sort
  std::sort(res.begin(),res.end(),compareFunction);//sort the vector

  return res;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    int debts_length;
    std::cin >> debts_length;
    ignore_line();
    std::vector<std::vector<std::string>> debts;
    for (int i = 0; i < debts_length; i++) {
        debts.emplace_back(get_words<std::string>());
    }
    std::vector<std::string> res = debt_records(debts);
    put_words(res);
}

