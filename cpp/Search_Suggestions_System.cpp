#include <string>
#include <vector>
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

  vector<string> search(string &w, int end) {
    Trie *cur = this;
    vector<Trie *> backup;
    for (int i = 0; i <= end; i++) {
      cur = cur->nexts[index(w[i])];
      if (!cur) {
        return {};
      }
    }
    return cur->allWords(3);
  }

  vector<string> allWords(int seek) {
    vector<string> res;
    if (end) {
      res.push_back("");
    }
    int i = 0;
    while (res.size() < seek && i < 26) {
      if (nexts[i]) {
        auto tmp = nexts[i]->allWords(seek - res.size());
        for (int j = 0; j < tmp.size(); j++) {
          res.push_back(static_cast<char>('a' + i) + tmp[j]);
        }
      }
      i++;
    }

    return res;
  }
};

class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string> &products,
                                           string &searchWord) {
    Trie *t = new Trie();
    for (auto &p : products) {
      t->insert(p);
    }

    vector<vector<string>> res;
    int l = searchWord.length();
    string v = "";
    for (int i = 0; i < l; i++) {
      v += searchWord[i];
      auto s = t->search(searchWord, i);
      for (int j = 0; j < s.size(); j++) {
        s[j] = v + s[j];
      }
      res.push_back(s);
    }

    return res;
  }
};
