import java.io.*;
import java.util.*;

public class UserCode {

    // Helper method to compute T(i) mod k safely.
    // T(i) = i*(i+1)/2, computed in a way that avoids overflow.
    public static long triangularMod(long i, long k) {
        if (i % 2 == 0) {
            long half = (i / 2) % k;
            long next = (i + 1) % k;
            return (half * next) % k;
        } else {
            long modI = i % k;
            long half = ((i + 1) / 2) % k;
            return (modI * half) % k;
        }
    }

    public static void solve(Scanner sc, PrintWriter out) {
        int t = sc.nextInt();
        while (t-- > 0) {
            long n = sc.nextLong();
            long k = sc.nextLong();
            // Determine period: if k is odd, period = k; if k is even, period = 2*k.
            long period = (k % 2 == 1) ? k : 2 * k;
            long countPerPeriod = 0;
            for (long i = 1; i <= period; i++) {
                if (triangularMod(i, k) == 0)
                    countPerPeriod++;
            }
            long fullPeriods = n / period;
            long remainder = n % period;
            long ans = fullPeriods * countPerPeriod;
            for (long i = 1; i <= remainder; i++) {
                if (triangularMod(i, k) == 0)
                    ans++;
            }
            out.println(ans);
        }
    }
}
