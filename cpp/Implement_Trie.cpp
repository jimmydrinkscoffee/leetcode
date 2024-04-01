#include <string>
using namespace std;

class Trie {
  Trie *nexts[26];
  bool end;

  inline int index(char c) { return c - 'a'; }

public:
  Trie() {
    end = false;
    for (auto &n : nexts) {
      n = NULL;
    }
  }

  void insert(string word) {
    int l = word.length();
    Trie *cur = this;
    for (int i = 0; i < l; i++) {
      int idx = index(word[i]);
      if (!cur->nexts[idx]) {
        cur->nexts[idx] = new Trie();
      }
      cur = cur->nexts[idx];
    }
    cur->end = true;
  }

  bool search(string word) {
    int l = word.length();
    Trie *cur = this;
    for (int i = 0; i < l; i++) {
      int idx = index(word[i]);
      if (!cur->nexts[idx]) {
        return false;
      }
      cur = cur->nexts[idx];
    }
    return cur->end;
  }

  bool startsWith(string prefix) {
    int l = prefix.length();
    Trie *cur = this;
    for (int i = 0; i < l; i++) {
      int idx = index(prefix[i]);
      if (!cur->nexts[idx]) {
        return false;
      }
      cur = cur->nexts[idx];
    }
    return cur != NULL;
  }
};
