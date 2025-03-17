#include <iostream>
#include <vector>
using namespace std;

#define ull unsigned long long
// Helper function to compute T(i) mod k safely without overflow.
ull triangularMod(ull i, ull k) {
    if (i % 2 == 0)
        return ((i / 2) % k * ((i + 1) % k)) % k;
    else
        return (i % k * (((i + 1) / 2) % k)) % k;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        ull n, k;
        cin >> n >> k;
        
        // Determine the period:
        ull period = (k % 2 == 1) ? k : 2 * k;
        
        // Precompute count of indices in one period where T(i) is divisible by k.
        ull countPerPeriod = 0;
        for (ull i = 1; i <= period; i++) {
            if (triangularMod(i, k) == 0)
                countPerPeriod++;
        }
        
        // Count full periods in [1, n] and then the remainder.
        ull fullPeriods = n / period;
        ull remainder = n % period;
        
        ull ans = fullPeriods * countPerPeriod;
        for (ull i = 1; i <= remainder; i++) {
            if (triangularMod(i, k) == 0)
                ans++;
        }
        
        cout << ans << "\n";
    }
}

