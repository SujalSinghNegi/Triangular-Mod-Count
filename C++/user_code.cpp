 // This will automatically redirect: stdin <- "a.txt", stdout -> "b.txt", stderr -> "error.txt"
#include <iostream>
#include <vector>
using namespace std;

// Helper function to compute T(i) mod k safely without overflow.
unsigned long long triangularMod(unsigned long long i, unsigned long long k) {
    if (i % 2 == 0)
        return ((i / 2) % k * ((i + 1) % k)) % k;
    else
        return (i % k * (((i + 1) / 2) % k)) % k;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        unsigned long long n, k;
        cin >> n >> k;
        
        // Determine the period:
        unsigned long long period = (k % 2 == 1) ? k : 2 * k;
        
        // Precompute count of indices in one period where T(i) is divisible by k.
        unsigned long long countPerPeriod = 0;
        for (unsigned long long i = 1; i <= period; i++) {
            if (triangularMod(i, k) == 0)
                countPerPeriod++;
        }
        
        // Count full periods in [1, n] and then the remainder.
        unsigned long long fullPeriods = n / period;
        unsigned long long remainder = n % period;
        
        unsigned long long ans = fullPeriods * countPerPeriod;
        for (unsigned long long i = 1; i <= remainder; i++) {
            if (triangularMod(i, k) == 0)
                ans++;
        }
        
        cout << ans << "\n";
    }
}

