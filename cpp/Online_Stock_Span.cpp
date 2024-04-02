#include <stack>
#include <utility>
using namespace std;

class StockSpanner {
  int d;
  stack<pair<int, int>> ps;

public:
  StockSpanner() {
    d = 0;
    ps = stack<pair<int, int>>();
  }

  int next(int p) {
    d++;
    while (!ps.empty() && ps.top().second <= p) {
      ps.pop();
    }
    int res = ps.empty() ? d : d - ps.top().first;
    ps.push({d, p});
    return res;
  }
};
