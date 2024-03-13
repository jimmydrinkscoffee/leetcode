#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// sum = sum of k - 1 largest n1's with n2's > n2[i]
// ans = max of ans and (sum + n1[i]) * n2[i]

class Solution {
public:
    typedef long long ll;
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<pair<ll, ll>> v;
        auto l = nums1.size();
        for (auto i = 0; i < l; i++) {
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.rbegin(), v.rend());

        priority_queue<int, vector<int>, greater<int>> q;
        ll sum = 0, res = -1;
        for (auto i = 0; i < l; i++) {
            auto &[n2, n1] = v[i];
            sum += n1;
            q.push(n1);
            if (q.size() == k) {
                res = max(res, sum * n2);
            }
            if (q.size() >= k) {
                sum -= q.top();
                q.pop();
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[]) {
    auto s = Solution();
    auto nums1 = vector<int>{4, 2, 3, 1, 1};
    auto nums2 = vector<int>{7, 5, 10, 9, 6};
    cout << s.maxScore(nums1, nums2, 3) << endl;
    return 0;
}
