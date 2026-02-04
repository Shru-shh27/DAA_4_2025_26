#include <bits/stdc++.h>
using namespace std;

int main() {
    int K = 3;
    vector<int> scores = {10, 20, 5, 15, 25, 8};

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int x : scores) {

        if (minHeap.size() < K) {
            minHeap.push(x);
            cout << -1 << endl;
        }
        else {
            if (x > minHeap.top()) {
                minHeap.pop();
                minHeap.push(x);
            }
            cout << minHeap.top() << endl;
        }
    }
}
