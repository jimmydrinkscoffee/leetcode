#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class SmallestInfiniteSet {
private:
    priority_queue<int, vector<int>, greater<int>> q;
    unordered_set<int> rm;

public:
    SmallestInfiniteSet() {
        for (int i = 1; i < 1005; i++) {
            q.push(i);
        }
    }

    int popSmallest() {
        int ans = q.top();
        q.pop();
        rm.insert(ans);
        return ans;
    }

    void addBack(int num) {
        if (rm.find(num) == rm.end()) {
            return;
        }
        q.push(num);
        rm.erase(num);
    }
};

int main() {
    SmallestInfiniteSet s = SmallestInfiniteSet();
    cout << s.popSmallest();
    return 0;
}
