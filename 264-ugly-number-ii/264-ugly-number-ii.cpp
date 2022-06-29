class Solution {
public:
    int nthUglyNumber(int n) {
        int *sieve = new int[n];
        
        sieve[0] = 1;
        
        int a = 0, b = 0, c = 0;
        
        for (int i = 1; i < n; i++) {
            sieve[i] = min(sieve[a]*2, min(sieve[b]*3, sieve[c]*5));
            if (sieve[i] == sieve[a]*2)
                a++;
            if (sieve[i] == sieve[b]*3)
                b++;
            if (sieve[i] == sieve[c]*5)
                c++;
        }
        
        for (int i = 0; i < n; i++) {
            cout << sieve[i] << " ";
        }
        
        return sieve[n-1];
    }
};