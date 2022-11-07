typedef long long ll;

class Solution {
public:
    bool helper(vector<int>& piles, ll h, ll speed) {
        ll time = 0;
        
        for (int i = 0; i < piles.size(); i++) {
            ll count = piles[i]/speed;
            if (piles[i] % speed)
                count++;
            time += count;
        }
        
        if (time <= h)
            return true;
        else
            return false;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        ll n = piles.size();
        ll ans = *max_element(piles.begin(), piles.end());
        
        ll start = 1, end = ans;
        
        while (start <= end) {
            ll mid = (start+end)/2;
            
            if (helper(piles, h, mid)) {
                ans = mid;
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }
        
        return ans;
    }
};