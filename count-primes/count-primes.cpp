class Solution {
public:
    int countPrimes(int n) {
        bool arr[n+1];
        for (int i = 0; i < sizeof(arr); i++) {
            arr[i] = true;
        }
        int count = 0;
        
        if (n == 2) {
            return 0;
        }
        
        for (int i = 2; i*i <= n; i++) {
            if (arr[i] == true) {
                for (int j = i*i; j <= n; j += i) {
                    arr[j] = false;
                }
            }
        }
        for (int i = 2; i < n; i++) {
            if (arr[i])
                count++;
        }
        return count;
    }
};