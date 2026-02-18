#include <vector>
#include <iostream>
using namespace std;

int lowerBound(const vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size();

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}

int main()
{
    vector<int> vec = {1, 2, 4, 4, 5, 7, 8};
    int target = 4;

    int lb = lowerBound(vec, target);

    cout << "Lower bound index: " << lb << "\n"; // Output: 2

    return 0;
}