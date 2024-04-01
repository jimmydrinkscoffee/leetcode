#include <cctype>
#include <string>
using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    int end = -1;
    for (int i = s.length() - 1; i >= 0; i--) {
      if (s[i] == ' ' && end >= 0) {
        return end - i;
      } else if (isalpha(s[i]) && end == -1) {
        end = i;
      }
    }
    return end + 1;
  }
};
