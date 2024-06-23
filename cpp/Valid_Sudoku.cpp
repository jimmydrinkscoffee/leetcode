#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
private:
  int val(char c) { return c - '1'; }

public:
  bool isValidSudoku(vector<vector<char>> &board) {
    bool row[9][9], col[9][9], box[3][3][9];
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') {
          continue;
        }
        int v = val(board[i][j]);
        if (row[i][v] || col[j][v] || box[i / 3][j / 3][v]) {
          return false;
        }
        row[i][v] = col[j][v] = box[i / 3][j / 3][v] = true;
      }
    }
    return true;
  }
};
