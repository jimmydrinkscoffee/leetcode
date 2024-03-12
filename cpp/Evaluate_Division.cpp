#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    unordered_map<string, unordered_map<string, double>> m;
    for (auto i = 0; i < equations.size(); i++) {
      m[equations[i][0]][equations[i][1]] = values[i];
      if (values[i] != 0) {
        m[equations[i][1]][equations[i][0]] = 1 / values[i];
      }
    }

    vector<double> res;
    for (auto i = 0; i < queries.size(); i++) {
      auto d = dfs(m, queries[i][0], queries[i][1], 1, i + 1);
      res.push_back(d != -1 ? d : -1);
    }

    return res;
  }

private:
  map<string, int> visited;

  double dfs(unordered_map<string, unordered_map<string, double>> m, string s,
             string e, double multiple, int cur) {
    if (m.find(s) == m.end()) {
      return -1;
    }

    for (auto [k, v] : m[s]) {
      if (visited[k] == cur) {
        continue;
      }

      visited[k] = cur;

      if (k == e) {
        return multiple * v;
      }

      auto r = dfs(m, k, e, multiple * v, cur);
      if (r >= 0) {
        return r;
      }
    }

    return -1;
  }
};

int main() { return 0; }
