#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
private:
  int vt[4]{1, 0, -1, 0}, hz[4]{0, 1, 0, -1};

public:
  bool exist(vector<vector<char>> &board, string &word) {
    vector<pair<int, int>> fs;
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (board[i][j] == word[0]) {
          fs.push_back({i, j});
        }
      }
    }

    vector<vector<bool>> v(board.size(), vector<bool>(board[0].size(), false));
    for (auto p : fs) {
      if (dfs(v, board, p.first, p.second, word, 1)) {
        return true;
      }
    }

    return false;
  }

  bool dfs(vector<vector<bool>> &v, vector<vector<char>> &b, int &i, int &j,
           string &w, int cur) {
    if (cur == w.length()) {
      return true;
    }

    v[i][j] = true;
    for (int k = 0; k < 4; k++) {
      int ni = i + vt[k], nj = j + hz[k];
      if (ni < 0 || ni >= v.size() || nj < 0 || nj > v[0].size() || v[ni][nj] ||
          b[ni][nj] != w[cur]) {
        continue;
      }
      if (dfs(v, b, ni, nj, w, cur + 1)) {
        v[i][j] = false;
        return true;
      }
    }

    v[i][j] = false;
    return false;
  }
};
