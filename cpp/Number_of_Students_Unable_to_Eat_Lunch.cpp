#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int countStudents(vector<int> &students, vector<int> &s) {
    queue<int> q;
    for (auto s : students) {
      q.push(s);
    }
    for (int i = 0; i < s.size(); i++) {
      bool p = false;
      int ql = q.size();
      for (int j = 0; j < ql; j++) {
        int f = q.front();
        q.pop();
        if (f == s[i]) {
          p = true;
          break;
        }
        q.push(f);
      }
      if (!p) {
        return s.size() - i;
      }
    }
    return 0;
  }
};
