import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class EllysThreePrimes
{
    public int[] getPrimes(int[] sums)
    {
        final int N = 100000;
        boolean[] isPrime = new boolean[N];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        List<Integer> primeList = new ArrayList<>();
        for (int i = 0; i < N; ++i) {
            if (isPrime[i]) {
                if (i >= 10000 && i <= 99999) {
                    primeList.add(i);
                }
                for (int j = 2; j * i < N; ++j) {
                    isPrime[i * j] = false;
                }
            }
        }
        
        int total = primeList.size();
        for (int i = 0; i < total; ++i) {
            for(int j = i + 1; j < total; ++j) {
                int value = 0;
                for (int k = 10000, q = 4; k > 0; k /= 10, --q) {
                    int t1 = (primeList.get(i) / k) % 10;
                    int t2 = (primeList.get(j) / k) % 10;
                    
                    int t3 = sums[q] - t1 - t2;
                    if (t3 > 9 || t3 < 0) {
                        break;
                    }
                    
                    value += t3 * k;
                }
                
                if (value < 10000 || value == primeList.get(i) || value == primeList.get(j)) {
                    continue;
                }
                
                if (isPrime[value]) {
                    return new int[] { primeList.get(i), primeList.get(j), value };
                }
            }
        }
        return new int[] {};
    }
    

}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
