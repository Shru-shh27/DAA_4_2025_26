#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cout << "Enter number of records: ";
    cin >> N;

    vector<char> arr(N);
    cout << "Enter attendance (P for Present, A for Absent):\n";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> mp;
    mp[0] = -1;   // Base case

    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i] == 'P')
            sum += 1;
        else if (arr[i] == 'A')
            sum -= 1;

        if (mp.find(sum) != mp.end()) {
            maxLen = max(maxLen, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }

    if (maxLen == 0) {
        cout << "\n0";
    } else {
        cout << "\nMaximum length of Stable Attendance Window :" << maxLen;
    }

    return 0;
}
