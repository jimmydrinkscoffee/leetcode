#include <algorithm>
#include <list>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> deckRevealedIncreasing(vector<int> &deck) {
    sort(deck.begin(), deck.end());
    list<int> l;
    l.push_back(deck[deck.size() - 1]);
    for (int i = deck.size() - 2; i >= 0; i--) {
      int back = l.back();
      l.pop_back();
      l.push_front(back);
      l.push_front(deck[i]);
    }
    return vector<int>{l.begin(), l.end()};
  }
};
