class Solution {
public:
    bool isPossible(vector<int>& arr, int k, long long maxTime) {
        long long curr = 0;
        int painters = 1;

        for (int len : arr) {
            if (curr + len <= maxTime) {
                curr += len;
            } else {
                painters++;
                curr = len;
                if (painters > k) return false;
            }
        }
        return true;
    }

    long long minTime(vector<int>& arr, int k) {
        long long low = *max_element(arr.begin(), arr.end());
        long long high = 0;
        for (int x : arr) high += x;

        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (isPossible(arr, k, mid)) {
                ans = mid;
                high = mid - 1;   
            } else {
                low = mid + 1;    
            }
        }
        return ans;
    }
};
