#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
  unordered_map<char, vector<char>> m;

public:
  Solution() {
    m['2'] = {'a', 'b', 'c'};
    m['3'] = {'d', 'e', 'f'};
    m['4'] = {'g', 'h', 'i'};
    m['5'] = {'j', 'k', 'l'};
    m['6'] = {'m', 'n', 'o'};
    m['7'] = {'p', 'q', 'r', 's'};
    m['8'] = {'t', 'u', 'v'};
    m['9'] = {'w', 'x', 'y', 'z'};
  }

  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      cout << "empty\n";
      return {};
    }

    vector<string> ans;
    for (char c : m[digits[0]]) {
      ans.push_back({c});
    }
    int l = digits.size();
    for (int i = 1; i < l; i++) {
      vector<string> tans;
      for (string s : ans) {
        for (char c : m[digits[i]]) {
          tans.push_back(s + c);
        }
      }
      ans = tans;
    }

    return ans;
  }
};
