#include <vector>
using namespace std;

class Solution {
private:
  void solve(int num, int k, int n, vector<int> &arr,
             vector<vector<int>> &ans) {
    if (arr.size() == k && n == 0) {
      ans.push_back(arr);
      arr.pop_back();
      return;
    }
    if (num > 9) {
      arr.pop_back();
      return;
    }

    arr.push_back(num);
    solve(num + 1, k, n - num, arr, ans);
    solve(num + 1, k, n, arr, ans);
  }

public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> arr;
    solve(1, k, n, arr, ans);
    return ans;
  }
};
