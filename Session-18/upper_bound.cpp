#include <vector>
#include <iostream>
using namespace std;

int upperBound(const vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size();

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target)
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

    int ub = upperBound(vec, target);

    cout << "Upper bound index: " << ub << "\n"; // Output: 4

    return 0;
}