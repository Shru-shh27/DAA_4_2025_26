class Solution {
public:
    bool isPossible(vector<int>& piles, int m, int h) {
        long long cnt = 0;
        for (int i = 0; i < piles.size(); i++) {
            cnt += (piles[i] + m - 1) / m;  
        }
        return cnt<=h;   }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (isPossible(piles, m, h)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};
