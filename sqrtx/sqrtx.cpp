class Solution {
public:
    int mySqrt(int x) {
        long long ans = 0, mid, start = 0, end = x;
        while (start <= end) {
            mid = (start+end)/2;
            if (mid*mid == x)
                return mid;
            else if (mid*mid < x) {
                start = mid+1;
                ans = mid;
            }
            else 
                end = mid-1;
        }
        return ans;
    }
};