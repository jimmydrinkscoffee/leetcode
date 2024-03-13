#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, less<int>> q(nums.begin(), nums.end());
        int res;
        while (k--) {
            res = q.top();
            q.pop();
        }
        return res;
    }
};
