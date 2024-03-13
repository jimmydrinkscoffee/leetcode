#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
private:
    int sol;
    int guess(int num) { return num == sol ? 0 : (num > sol ? 1 : -1); }

public:
    Solution(int sol) { this->sol = sol; }

    int guessNumber(int n) {
        int l = 0, r = n;
        int pv = l + (r - l) / 2;
        while (r >= l) {
            switch (guess(pv)) {
            case -1:
                r = pv - 1;
                break;
            case 1:
                l = pv + 1;
                break;
            default:
                return pv;
            }
            pv = l + (r - l) / 2;
        }
        return 0;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution(6);
    cout << s.guessNumber(10);

    return 0;
}
