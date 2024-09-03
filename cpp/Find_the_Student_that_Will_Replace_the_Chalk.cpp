#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int chalkReplacer(vector<int> &chalk, int k) {
    k = k % accumulate(chalk.begin(), chalk.end(), (long)0);
    for (int i = 0; i < chalk.size(); i++) {
      if (k < chalk[i]) {
        return i;
      }
      k -= chalk[i];
    }
    return -1;
  }
};
