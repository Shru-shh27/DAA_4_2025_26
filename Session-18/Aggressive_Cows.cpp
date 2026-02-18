#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool helper(vector<int> &stalls, int k, int dis)
    {
        int count = 1; 
        int lastPlaced = stalls[0];     
        
        for(int i = 1; i < stalls.size(); i++)
        {
            if(stalls[i] - lastPlaced >= dis)
            {
                count++;
                lastPlaced = stalls[i];
                
                if(count >= k)
                    return true;
            }
        }
        
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        
        sort(stalls.begin(), stalls.end());
        
        int l = 1;
        int n = stalls.size();
        int h = stalls[n-1] - stalls[0];
        int answer = 0;
        
        while(l <= h)
        {
            int mid = l + (h - l) / 2;
            
            if(helper(stalls, k, mid))
            {
                answer = mid;      
                l = mid + 1;      
            }
            else
            {
                h = mid - 1;       
            }
        }
        
        return answer;
    }
};