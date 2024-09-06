#include <bitset>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *modifiedList(vector<int> &nums, ListNode *head) {
    bitset<100001> s;
    for (auto n : nums) {
      s.set(n);
    }
    while (head && s[head->val]) {
      auto tmp = head;
      head = head->next;
      delete tmp;
    }
    auto cur = head;
    while (cur) {
      while (cur->next && s[cur->next->val]) {
        auto tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
      }
      cur = cur->next;
    }
    return head;
  }
};
