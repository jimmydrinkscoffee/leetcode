#include <ios>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &tmp) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l = tmp.size();
    vector<int> res(l, 0);
    stack<int> idx;
    idx.push(0);
    for (int i = 1; i < l; i++) {
      while (!idx.empty() && tmp[i] > tmp[idx.top()]) {
        res[idx.top()] = i - idx.top();
        idx.pop();
      }
      idx.push(i);
    }

    return res;
  }
};
