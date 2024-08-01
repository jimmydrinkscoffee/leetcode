#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int countSeniors(vector<string> &details) {
    int ans = 0;
    for (auto d : details) {
      auto a = d.substr(12, 2);
      if (stoi(a) > 60) {
        ans++;
      }
    }
    return ans;
  }
};
